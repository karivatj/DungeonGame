/*
 * glut_engine.h 1.02 by Jarkko Vatjus-Anttila
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
 * v1.0   - Initial prototype set.
 * v1.01  - Added two function prototypes:
 *             glut_clearText() and
 *             glut_clearGraphics()
 * v1.02  - Added function prototype:
 *             glut_toggleBlending()
 * v1.03  - Added function prototype:
 *			   glut_ChangeTileSet()
 */

#ifndef GLUT_ENGINE_H
#define GLUT_ENGINE_H

int glut_getXResolution(void);
int glut_getYResolution(void);
int glut_getTileset(void);
void glut_quit(void);
void glut_redraw(void);
void glut_clearText(void);
void glut_clearGraphics(void);
void glut_clearScreen(void);
void glut_drawGraphics(int x, int y, int id);
void glut_drawText(int x, int y, char *text, int font);
void glut_toggleBlending(void);
int glut_ChangeTileSet(int tile);

#endif /* GLUT_ENGINE_H */

