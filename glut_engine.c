 /*
 * glut_engine.c 1.02 by Jarkko Vatjus-Anttila
 *
 * This is a frontend for creating graphical roque like
 * games.
 *
 * Currently implemented functions:
 *  - glut_getXResolution
 *  - glut_getYResolution
 *  - glut_getTileset
 *  - glut_quit
 *  - glut_redraw
 *  - glut_clearText
 *  - glut_clearGraphics
 *  - glut_clearScreen
 *  - glut_drawGraphics
 *  - glut_drawText
 *
 * Version history:
 * v1.0   - Initial working version.
 * v1.01  - Added functions:
 *             glut_clearText() and
 *             glut_clearGraphics()
 *        - Fixed small bug from graphics routine. Graphic tiles
 *          were treated one pixel too small.
 * v1.02  - Added function:
 *             glut_toggleBlending()
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>       /* for cos(), sin(), and sqrt() */

#ifdef WIN32
#include "windows.h"	/* Smart ass windows shit has fucked up the */
#endif					/* GL includes. This is not the acse for linux. */

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>    /* OpenGL Utility Toolkit header */

#include "glut_engine.h"

/*
 * External hook-functions kari provides
 */
extern void kari_mouse_handler(int button, int state, int x, int y);
extern void kari_key_handler(int key, int x, int y);
extern void kari_init_handler(void);
extern void kari_cleanup_handler(void);

/* Local prototypes */
static int readfile(char *filename, int *filelength, unsigned char **output, int offset);
static GLvoid glPrint(GLint x, GLint y, char *string, int set);
static GLvoid BuildFont(GLvoid);
static GLvoid KillFont(GLvoid);
static void redraw(void);
static void mouse(int button, int state, int x, int y);
static void motion(int x, int y);
static void visible(int vis);
static void key(unsigned char c, int x, int y);
static void special(int k, int x, int y);
static GLint LoadBMP(char *filename, int x, int y);
static int initGL(void);
static void parseargs(int argc, char **argv);

/* local typedefs */
typedef struct {
	int reserved;
	int x;
	int y;
	int block;
	int blending;
} EVENT_GFX;

typedef struct {
	int reserved;
	int x;
	int y;
	int font;
	int blending;
	char text[128];
} EVENT_TEXT;

/*****************************************************/

#define FONT_X						(3*tileset/4)
#define FONT_Y						tileset
#define BMP_OFFSET				54

#define MAX_TEXT_EVENTS	128
#define MAX_GFX_EVENTS		10240

/* display lists and textures */
static int fonttexture = 0;
static int tiletexture = 0;

static int tileset = 16;
static GLuint fontbase = 0;

/* display events */
static EVENT_GFX  gfx_events[MAX_GFX_EVENTS];
static EVENT_TEXT text_events[MAX_TEXT_EVENTS];

/*screen resolution */
static int xres = 800; /* 640/8 = 80, 640/16 = 40 */
static int yres = 600; /* 480/8 = 60, 480/16 = 30 */
static int glut_blending = 0;

/*****************************************************
 * Local functions:
 */

static int readfile(char *filename, int *filelength, unsigned char **output, int offset)
{
	FILE *file;
	unsigned int length, read;
	char *buffer;

	file = fopen(filename, "rb");
	if (file == NULL) return (-1);

	fseek(file, 0, SEEK_END);
	length = ftell(file) + 1;
	rewind(file);

	if (offset > 0)
	{
		fseek(file, offset, SEEK_SET);
	}

	buffer = (char *)malloc(length-offset);
	if (buffer == NULL)
	{
		fclose(file);
		return (-1);
	}
	memset(buffer, 0, length-offset);

	read = fread(buffer, 1, length-offset-1, file);
	fclose(file);

  if (filelength != NULL) *filelength = length;
  *output = buffer;

//	printf("File I/O, %d bytes read\n", length-offset-1);
  return(0);
}

static GLvoid glPrint(GLint x, GLint y, char *string, int set)	// Where The Printing Happens
{
	if ((set < 0) || (set > 1)) set = 1;

	glBindTexture(GL_TEXTURE_2D, fonttexture);	// Select Our Font Texture
	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glPushMatrix();										// Store The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix
	glOrtho(0,(float)xres,(float)yres,0,-1,1);							// Set Up An Ortho Screen
	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glPushMatrix();										// Store The Modelview Matrix
	glLoadIdentity();									// Reset The Modelview Matrix
	glTranslated(x*tileset,FONT_Y+y*tileset,0);								// Position The Text (0,0 - Bottom Left)
	glListBase(fontbase-32+(128*set));					// Choose The Font Set (0 or 1)
	glCallLists(strlen(string),GL_BYTE,string);			// Write The Text To The Screen
	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glPopMatrix();										// Restore The Old Projection Matrix
	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glPopMatrix();										// Restore The Old Projection Matrix
}

static GLvoid BuildFont(GLvoid)								// Build Our Font Display List
{
	float cx;											// Holds Our X Character Coord
	float cy;											// Holds Our Y Character Coord
	int loop;

	fontbase=glGenLists(256);							// Creating 256 Display Lists
	glBindTexture(GL_TEXTURE_2D, fonttexture);	// Select Our Font Texture
//	printf("Building fontlist, baseentry=%d\n", fontbase);
	for (loop=0; loop<256; loop++)						// Loop Through All 256 Lists
	{
		cx=(float)(loop%16)/16.0f;						// X Position Of Current Character
		cy=(float)(loop/16)/16.0f;						// Y Position Of Current Character

		glNewList(fontbase+loop,GL_COMPILE);			// Start Building A List
			glBegin(GL_QUADS);							// Use A Quad For Each Character
				glTexCoord2f(cx,1.0-(cy+0.0625f));			// Texture Coord (Bottom Left)
				glVertex2i(0,0);						// Vertex Coord (Bottom Left)
				glTexCoord2f(cx+0.0625f,1.0-(cy+0.0625f));	// Texture Coord (Bottom Right)
				glVertex2i(FONT_X,0);						// Vertex Coord (Bottom Right)
				glTexCoord2f(cx+0.0625f,1.0-cy);			// Texture Coord (Top Right)
				glVertex2i(FONT_X,-FONT_Y);						// Vertex Coord (Top Right)
				glTexCoord2f(cx,1.0-cy);					// Texture Coord (Top Left)
				glVertex2i(0,-FONT_Y);						// Vertex Coord (Top Left)
			glEnd();									// Done Building Our Quad (Character)
			glTranslated(FONT_X,0,0);						// Move To The Right Of The Character
		glEndList();									// Done Building The Display List
	}													// Loop Until All 256 Are Built
}

static GLvoid KillFont(GLvoid)									// Delete The Font
{
	if (fontbase != 0)
	{
		glDeleteLists(fontbase, 256);						// Delete All 256 Display Lists
	}
}

/*****************************************************/

static void redraw(void)
{
	int i;

#if 1
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0,(float)xres,(float)yres,0,-1,1);							// Set Up An Ortho Screen
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
#endif

	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	glBindTexture(GL_TEXTURE_2D, tiletexture);
	for (i=0; i<MAX_GFX_EVENTS; i++)
	{
		if (gfx_events[i].reserved == 0)
		{
			break;
		}
		glLoadIdentity();
		glTranslated(gfx_events[i].x*tileset, gfx_events[i].y*tileset, 0);
		if (gfx_events[i].blending == 0)
		{
			glDisable(GL_BLEND);
			glColor4d(1, 1, 1, 1);
		}
		else
		{
			glEnable(GL_BLEND);
			glColor4d(1, 1, 1, 0.0);
		}
		glBegin(GL_POLYGON);
			if (tileset == 8)
			{
				glTexCoord2f(tileset*(gfx_events[i].block%32 + 0)/256.0, 1.0-tileset*(gfx_events[i].block/32 + 0)/128.0);
				glVertex3f(0, 0, 0);
				glTexCoord2f(tileset*(gfx_events[i].block%32 + 1)/256.0, 1.0-tileset*(gfx_events[i].block/32 + 0)/128.0);
				glVertex3f(tileset, 0, 0);
				glTexCoord2f(tileset*(gfx_events[i].block%32 + 1)/256.0, 1.0-tileset*(gfx_events[i].block/32 + 1)/128.0);
				glVertex3f(tileset, tileset, 0);
				glTexCoord2f(tileset*(gfx_events[i].block%32 + 0)/256.0, 1.0-tileset*(gfx_events[i].block/32 + 1)/128.0);
				glVertex3f(0, tileset, 0);
			}
			else if (tileset == 16)
			{
				glTexCoord2f(tileset*(gfx_events[i].block%32 + 0)/512.0, 1.0-tileset*(gfx_events[i].block/32 + 0)/256.0);
//			glColor4f(1.0, 1.0, 1.0, 0.9);
				glVertex3f(0, 0, 0);
				glTexCoord2f(tileset*(gfx_events[i].block%32 + 1)/512.0, 1.0-tileset*(gfx_events[i].block/32 + 0)/256.0);
//			glColor4f(1.0, 1.0, 1.0, 0.9);
				glVertex3f(tileset, 0, 0);
				glTexCoord2f(tileset*(gfx_events[i].block%32 + 1)/512.0, 1.0-tileset*(gfx_events[i].block/32 + 1)/256.0);
//			glColor4f(1.0, 1.0, 1.0, 0.9);
				glVertex3f(tileset, tileset, 0);
				glTexCoord2f(tileset*(gfx_events[i].block%32 + 0)/512.0, 1.0-tileset*(gfx_events[i].block/32 + 1)/256.0);
//			glColor4f(1.0, 1.0, 1.0, 0.9);
				glVertex3f(0, tileset, 0);
			}
			else if (tileset==32)
			{
				glTexCoord2f(tileset*(gfx_events[i].block%32 + 0)/1024.0, 1.0-tileset*(gfx_events[i].block/32 + 0)/256.0);
//			glColor4f(1.0, 1.0, 1.0, 0.9);
				glVertex3f(0, 0, 0);
				glTexCoord2f(tileset*(gfx_events[i].block%32 + 1)/1024.0, 1.0-tileset*(gfx_events[i].block/32 + 0)/256.0);
//			glColor4f(1.0, 1.0, 1.0, 0.9);
				glVertex3f(tileset, 0, 0);
				glTexCoord2f(tileset*(gfx_events[i].block%32 + 1)/1024.0, 1.0-tileset*(gfx_events[i].block/32 + 1)/256.0);
//			glColor4f(1.0, 1.0, 1.0, 0.9);
				glVertex3f(tileset, tileset, 0);
				glTexCoord2f(tileset*(gfx_events[i].block%32 + 0)/1024.0, 1.0-tileset*(gfx_events[i].block/32 + 1)/256.0);
//			glColor4f(1.0, 1.0, 1.0, 0.9);
				glVertex3f(0, tileset, 0);

			}








		glEnd();
	}

	for (i=0; i<MAX_TEXT_EVENTS; i++)
	{
		if (text_events[i].reserved == 0)
		{
			break;
		}
		glPrint(text_events[i].x,
						text_events[i].y,
						text_events[i].text,
						text_events[i].font);
	}

  glutSwapBuffers();
}

/*****************************************************/

static void mouse(int button, int state, int x, int y)
{
	kari_mouse_handler(button, state, x, y);
}

/*****************************************************/

static void motion(int x, int y)
{
}

/*****************************************************/

static void visible(int vis)
{
}

/*****************************************************/

static void key(unsigned char c, int x, int y)
{
//	printf("keyhandler. key %c (=0x%x) x=%d y=%d\n", c, c, x, y);
	kari_key_handler(c, x, y);
}

/*****************************************************/

static void special(int k, int x, int y)
{
}

/*****************************************************/

static GLint LoadBMP(char * filename, int x, int y)
{
	int rc, t;
	GLuint temp = 0;
	GLuint mode = GL_RGB;
	unsigned char *b;
	unsigned char *buffer;
	rc = readfile(filename, NULL, &buffer, BMP_OFFSET);

	if (rc == 0)
	{
		for (t=0; t<3*x*y; t+=3)
		{
			temp = buffer[t];
			buffer[t] = buffer[t+2];
			buffer[t+2] = temp;
		}

#if 1
		b = malloc(x*y*4*sizeof(unsigned char));
		if (b != NULL)
		{
			for (t=0; t<x*y; t++)
			{
				b[4*t+0] = buffer[3*t+0];
				b[4*t+1] = buffer[3*t+1];
				b[4*t+2] = buffer[3*t+2];
				if ((b[4*t] == 0) && (b[4*t+1] == 0) && (b[4*t+2] == 0))
				{
					b[4*t+3] = 0x00;
				}
				else b[4*t+3] = 0xff;
			}
			free(buffer);
			buffer = b;
			mode = GL_RGBA;
		}
#endif

		glGenTextures(1, &temp);
		glBindTexture(GL_TEXTURE_2D, temp);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, x, y, 0, mode, GL_UNSIGNED_BYTE, buffer);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); // Linear Filtering
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); // Linear Filtering
		free(buffer);
		return(temp);
	}
//	else printf("Fileread failed\n");

	return (-1);
}

/*****************************************************/

static int initGL(void)
{
	glDisable(GL_LIGHTING);
	glDisable(GL_DEPTH_TEST);

	glEnable(GL_TEXTURE_2D);

	glShadeModel(GL_SMOOTH);
	glEnable(GL_SMOOTH);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glEnable(GL_NORMALIZE);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);

	fonttexture = LoadBMP("font.bmp", 256, 256);
	if (fonttexture == -1)
	{
		printf("Unable to load font.bmp\n");
		return(-1);
	}
	else BuildFont();
	glut_ChangeTileSet(tileset);
	return (0);
}

/*****************************************************/

static void parseargs(int argc, char **argv)
{
	int i;
	if (argc <= 1)
	{
		printf(" USAGE: %s [-size (8|16)]\n", argv[0]);
		printf("    -size (8|16) chooses between 8x8 and 16x16 tileset.\n");
		return;
	}
	for (i=0; i<argc; i++)
	{
		if (strncmp(argv[i], "-size", 5) == 0)
		{
			if (i+1 < argc)
			{
				switch(atoi(argv[i+1]))
				{
					default:
					case 8:
						printf("Using tileset 8x8\n");
						tileset = 8;
						xres = 320;
						yres = 240;
						break;
					case 16:
						printf("Using tileset 16x16\n");
						tileset = 16;
						xres = 640;
						yres = 480;
						break;
				}
			}
		}
	}
}

/*****************************************************/

static int seek_gfxevent(void)
{
	int i;
	for (i=0; i<MAX_GFX_EVENTS; i++)
	{
		if (gfx_events[i].reserved == 0)
		{
			return(i);
		}
	}
	return(-1);
}

static int seek_textevent(void)
{
	int i;
	for (i=0; i<MAX_TEXT_EVENTS; i++)
	{
		if (text_events[i].reserved == 0)
		{
			return(i);
		}
	}
	return(-1);
}

/*****************************************************
 * Global functions:
 */
int glut_ChangeTileSet(int tile)
{


/*	if (tiletexture != -1)
	{
		glDestroyTexture(tiletexture);
		tiletexture = -1;
	}
*/

	if (tile == 8)
	{
		tiletexture = LoadBMP("8x8.bmp", 256, 128);
		if (tiletexture == -1)
		{
			printf("Unable to load 8x8.bmp\n");
			return(-1);
		}
		printf("8x8 tileset loaded\n");
	}
	else if (tile == 16)
	{
		tiletexture = LoadBMP("16x16.bmp", 512, 256);
		if (tiletexture == -1)
		{
			printf("Unable to load 16x16.bmp\n");
			return(-1);
		}
		printf("16x16 tileset loaded\n");
	}
	else if (tile == 32)
	{
		tiletexture = LoadBMP("32x32.bmp", 1024, 512);
		if (tiletexture == -1)
		{
			printf("Unable to load 32x32.bmp\n");
			return(-1);
		}
		printf("32x32 tileset loaded\n");
	}
	else
	{
		printf("Illegal tileset\n");
		return(-1);
	}
	tileset= tile;
	return 0;
}

int glut_getXResolution(void)
{

	return xres;
}

int glut_getYResolution(void)
{
	return yres;
}

int glut_getTileset(void)
{
	return tileset;
}

void glut_quit(void)
{
	kari_cleanup_handler();
	KillFont();
	exit(0);
}

void glut_redraw(void)
{
	glutPostRedisplay();
}

void glut_clearText(void)
{
	int i;
	for (i=0; i<MAX_TEXT_EVENTS; i++)
	{
		text_events[i].reserved = 0;
	}
}

void glut_clearGraphics(void)
{
	int i;
	for (i=0; i<MAX_GFX_EVENTS; i++)
	{
		gfx_events[i].reserved = 0;
	}
}

void glut_clearScreen(void)
{
	glut_clearText();
	glut_clearGraphics();
}

void glut_drawGraphics(int x, int y, int id)
{
	int index;
	index = seek_gfxevent();
	if (index != -1)
	{
		gfx_events[index].reserved = 1;
		gfx_events[index].x = x;
		gfx_events[index].y = y;
		gfx_events[index].block = id;
		gfx_events[index].blending = glut_blending;
	}
}

void glut_drawText(int x, int y, char *text, int font)
{
	int index;
	index = seek_textevent();
	if (index != -1)
	{
		int len;
		len = strlen(text);
		if (len >= 256) len = 255;
		text_events[index].reserved = 1;
		text_events[index].x = x;
		text_events[index].y = y;
		text_events[index].font = font;
		text_events[index].blending = glut_blending;
		memcpy(text_events[index].text, text, len);
		text_events[index].text[len] = '\0';
	}
}

void glut_toggleBlending(void)
{
	glut_blending = 1-glut_blending;
}

/*****************************************************
 * main
 */

int glut_window;

int main(int argc, char **argv)
{

	parseargs(argc, argv);
	glutInit(&argc, argv);

  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutInitWindowSize(xres, yres);
  glut_window = glutCreateWindow("---==KDS==---");

  /* Register GLUT callbacks. */
  glutDisplayFunc(redraw);
  glutMouseFunc(mouse);
  glutMotionFunc(motion);
  glutVisibilityFunc(visible);
  glutKeyboardFunc(key);
  glutSpecialFunc(special);

	if (initGL() != 0)
	{
		printf("Error loading texture\n");
		exit(0);
	}

	memset(gfx_events, 0, sizeof(gfx_events));
	memset(text_events, 0, sizeof(text_events));

	kari_init_handler();
  glutMainLoop();
  return 0;             /* ANSI C requires main to return int. */
}
