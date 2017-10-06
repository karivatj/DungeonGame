
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#include "game.h"
#include "glut_engine.h"

void aija (void)
{
/************************************************************************/
/* Making The Character:                                                                                                                          	 */
/************************************************************************/
			/*Human*/
			if(ukko.sukupuoli==1 && ukko.laji==1 && ukko.luokka==1)
			{
				glut_drawGraphics(MAP_OFFSET_X+ukko.x, MAP_OFFSET_Y+ukko.y,39);
				return;
			}
			if(ukko.sukupuoli==1 && ukko.laji==1 && ukko.luokka==2)
			{
				glut_drawGraphics(MAP_OFFSET_X+ukko.x, MAP_OFFSET_Y+ukko.y,122);
				return;
			}
			if(ukko.sukupuoli==2 && ukko.laji==1 && ukko.luokka==1)
			{
					glut_drawGraphics(MAP_OFFSET_X+ukko.x, MAP_OFFSET_Y+ukko.y,39);
					return;
			}
			if(ukko.sukupuoli==2 && ukko.laji==1 && ukko.luokka==2)
			{
				glut_drawGraphics(MAP_OFFSET_X+ukko.x, MAP_OFFSET_Y+ukko.y,122);
				return;
			}
			if(ukko.sukupuoli==2 && ukko.laji==1 && ukko.luokka==2)
			{
				glut_drawGraphics(MAP_OFFSET_X+ukko.x, MAP_OFFSET_Y+ukko.y,122);
				return;
			}
			if(ukko.sukupuoli==2 && ukko.laji==1 && ukko.luokka==3)
			{
				glut_drawGraphics(MAP_OFFSET_X+ukko.x, MAP_OFFSET_Y+ukko.y,133);
				return;
    		}
            if(ukko.sukupuoli==1 && ukko.laji==1 && ukko.luokka==3)
			{
				glut_drawGraphics(MAP_OFFSET_X+ukko.x, MAP_OFFSET_Y+ukko.y,133);
				return;
			}
			/********/
			/*Skeleton*/
			if(ukko.sukupuoli==1 && ukko.laji==2 && ukko.luokka==1)
			{
				glut_drawGraphics(MAP_OFFSET_X+ukko.x, MAP_OFFSET_Y+ukko.y,124 );
				return;
			}
			if(ukko.sukupuoli==1 && ukko.laji==2 && ukko.luokka==2)
			{
				glut_drawGraphics(MAP_OFFSET_X+ukko.x, MAP_OFFSET_Y+ukko.y,121);
				return;
			}
    		if(ukko.sukupuoli==2 && ukko.laji==2 && ukko.luokka==2)
			{
				glut_drawGraphics(MAP_OFFSET_X+ukko.x, MAP_OFFSET_Y+ukko.y,121);
				return;
			}
			if(ukko.sukupuoli==2 && ukko.laji==2 && ukko.luokka==1)
			{
				glut_drawGraphics(MAP_OFFSET_X+ukko.x, MAP_OFFSET_Y+ukko.y,124);
				return;
			}
			if(ukko.sukupuoli==2 && ukko.laji==2 && ukko.luokka==3)
			{
				glut_drawGraphics(MAP_OFFSET_X+ukko.x, MAP_OFFSET_Y+ukko.y,138);
				return;
    		}
            if(ukko.sukupuoli==1 && ukko.laji==2 && ukko.luokka==3)
			{
				glut_drawGraphics(MAP_OFFSET_X+ukko.x, MAP_OFFSET_Y+ukko.y,138);
				return;
			}

			/*******/
			/*Wraith*/
			if(ukko.sukupuoli==1 && ukko.laji==3 && ukko.luokka==2)
			{
				glut_drawGraphics(MAP_OFFSET_X+ukko.x, MAP_OFFSET_Y+ukko.y,105);
				return;
			}
			if(ukko.sukupuoli==1 && ukko.laji==3 && ukko.luokka==1)
			{
				glut_drawGraphics(MAP_OFFSET_X+ukko.x, MAP_OFFSET_Y+ukko.y,104);
				return;
			}
			if(ukko.sukupuoli==2 && ukko.laji==3 && ukko.luokka==2)
			{
				glut_drawGraphics(MAP_OFFSET_X+ukko.x, MAP_OFFSET_Y+ukko.y,105);
				return;
			}
			if(ukko.sukupuoli==2 && ukko.laji==3 && ukko.luokka==1)
			{
				glut_drawGraphics(MAP_OFFSET_X+ukko.x, MAP_OFFSET_Y+ukko.y,104);
				return;
			}
			if(ukko.sukupuoli==2 && ukko.laji==3 && ukko.luokka==3)
			{
				glut_drawGraphics(MAP_OFFSET_X+ukko.x, MAP_OFFSET_Y+ukko.y,135);
				return;
    		}
            if(ukko.sukupuoli==1 && ukko.laji==3 && ukko.luokka==3)
			{
				glut_drawGraphics(MAP_OFFSET_X+ukko.x, MAP_OFFSET_Y+ukko.y,135);
				return;
			}
			/*********/
			/*Half-Titan*/
            if(ukko.sukupuoli==1 && ukko.laji==4 && ukko.luokka==1)
			{
				glut_drawGraphics(MAP_OFFSET_X+ukko.x, MAP_OFFSET_Y+ukko.y,110);
				return;
			}
            if(ukko.sukupuoli==1 && ukko.laji==4 && ukko.luokka==2)
			{
				glut_drawGraphics(MAP_OFFSET_X+ukko.x, MAP_OFFSET_Y+ukko.y,111);
				return;
			}
            if(ukko.sukupuoli==2 && ukko.laji==4 && ukko.luokka==1)
			{
				glut_drawGraphics(MAP_OFFSET_X+ukko.x, MAP_OFFSET_Y+ukko.y,110);
				return;
			}
    	    if(ukko.sukupuoli==2 && ukko.laji==4 && ukko.luokka==2)
			{
				glut_drawGraphics(MAP_OFFSET_X+ukko.x, MAP_OFFSET_Y+ukko.y,111);
				return;
			}
			if(ukko.sukupuoli==2 && ukko.laji==4 && ukko.luokka==3)
			{
				glut_drawGraphics(MAP_OFFSET_X+ukko.x, MAP_OFFSET_Y+ukko.y,132);
				return;
    		}
            if(ukko.sukupuoli==1 && ukko.laji==4 && ukko.luokka==3)
			{
				glut_drawGraphics(MAP_OFFSET_X+ukko.x, MAP_OFFSET_Y+ukko.y,132);
				return;
			}
			/******/
			/*Sprite*/
            if(ukko.sukupuoli==2 && ukko.laji==5 && ukko.luokka==1)
			{
				glut_drawGraphics(MAP_OFFSET_X+ukko.x, MAP_OFFSET_Y+ukko.y,125);
			return;
    		}
            if(ukko.sukupuoli==2 && ukko.laji==5 && ukko.luokka==2)
			{
				glut_drawGraphics(MAP_OFFSET_X+ukko.x, MAP_OFFSET_Y+ukko.y,126);
				return;
			}
			if(ukko.sukupuoli==1 && ukko.laji==5 && ukko.luokka==1)
			{
				glut_drawGraphics(MAP_OFFSET_X+ukko.x, MAP_OFFSET_Y+ukko.y,125);
	 			return;
			}
            if(ukko.sukupuoli==1 && ukko.laji==5 && ukko.luokka==2)
			{
				glut_drawGraphics(MAP_OFFSET_X+ukko.x, MAP_OFFSET_Y+ukko.y,126);
				return;
			}
			if(ukko.sukupuoli==2 && ukko.laji==5 && ukko.luokka==3)
			{
				glut_drawGraphics(MAP_OFFSET_X+ukko.x, MAP_OFFSET_Y+ukko.y,136);
				return;
    		}
            if(ukko.sukupuoli==1 && ukko.laji==5 && ukko.luokka==3)
			{
				glut_drawGraphics(MAP_OFFSET_X+ukko.x, MAP_OFFSET_Y+ukko.y,136);
				return;
			}
			/******/
			/*Golem*/
			if(ukko.sukupuoli==1 && ukko.laji==6 && ukko.luokka==2)
			{
				glut_drawGraphics(MAP_OFFSET_X+ukko.x, MAP_OFFSET_Y+ukko.y,127);
				return;
			}
			if(ukko.sukupuoli==1 && ukko.laji==6 && ukko.luokka==1)
			{
				glut_drawGraphics(MAP_OFFSET_X+ukko.x, MAP_OFFSET_Y+ukko.y,112);
				return;
			}
			if(ukko.sukupuoli==2 && ukko.laji==6 && ukko.luokka==2)
			{
				glut_drawGraphics(MAP_OFFSET_X+ukko.x, MAP_OFFSET_Y+ukko.y,127);
				return;
			}
			if(ukko.sukupuoli==2 && ukko.laji==6 && ukko.luokka==1)
			{
				glut_drawGraphics(MAP_OFFSET_X+ukko.x, MAP_OFFSET_Y+ukko.y,112);
				return;
			}
			if(ukko.sukupuoli==2 && ukko.laji==6 && ukko.luokka==3)
			{
				glut_drawGraphics(MAP_OFFSET_X+ukko.x, MAP_OFFSET_Y+ukko.y,139);
				return;
    		}
            if(ukko.sukupuoli==1 && ukko.laji==6 && ukko.luokka==3)
			{
				glut_drawGraphics(MAP_OFFSET_X+ukko.x, MAP_OFFSET_Y+ukko.y,139);
				return;
			}
			/*********/
			/*Draconian*/
			if(ukko.sukupuoli==1 && ukko.laji==7 && ukko.luokka==2)
			{
				glut_drawGraphics(MAP_OFFSET_X+ukko.x, MAP_OFFSET_Y+ukko.y,129);
				return;
			}
			if(ukko.sukupuoli==1 && ukko.laji==7 && ukko.luokka==1)
			{
				glut_drawGraphics(MAP_OFFSET_X+ukko.x, MAP_OFFSET_Y+ukko.y,128);
				return;
			}
			if(ukko.sukupuoli==2 && ukko.laji==7 && ukko.luokka==2)
			{
				glut_drawGraphics(MAP_OFFSET_X+ukko.x, MAP_OFFSET_Y+ukko.y,129);
				return;
			}
			if(ukko.sukupuoli==2 && ukko.laji==7 && ukko.luokka==1)
			{
				glut_drawGraphics(MAP_OFFSET_X+ukko.x, MAP_OFFSET_Y+ukko.y,128);
				return;
			}
			if(ukko.sukupuoli==2 && ukko.laji==7 && ukko.luokka==3)
			{
				glut_drawGraphics(MAP_OFFSET_X+ukko.x, MAP_OFFSET_Y+ukko.y,137);
				return;
    		}
            if(ukko.sukupuoli==1 && ukko.laji==7 && ukko.luokka==3)
			{
				glut_drawGraphics(MAP_OFFSET_X+ukko.x, MAP_OFFSET_Y+ukko.y,137);
				return;
			}
			/*********/
			/*Dwarf*/
			if(ukko.sukupuoli==1 && ukko.laji==8 && ukko.luokka==2)
			{
				glut_drawGraphics(MAP_OFFSET_X+ukko.x, MAP_OFFSET_Y+ukko.y,131);
				return;
			}
			if(ukko.sukupuoli==1 && ukko.laji==8 && ukko.luokka==1)
			{
				glut_drawGraphics(MAP_OFFSET_X+ukko.x, MAP_OFFSET_Y+ukko.y,130);
				return;
			}
			if(ukko.sukupuoli==2 && ukko.laji==8 && ukko.luokka==2)
			{
				glut_drawGraphics(MAP_OFFSET_X+ukko.x, MAP_OFFSET_Y+ukko.y,131);
				return;
			}
			if(ukko.sukupuoli==2 && ukko.laji==8 && ukko.luokka==1)
			{
				glut_drawGraphics(MAP_OFFSET_X+ukko.x, MAP_OFFSET_Y+ukko.y,130);
				return;
			}
			if(ukko.sukupuoli==2 && ukko.laji==8 && ukko.luokka==3)
			{
				glut_drawGraphics(MAP_OFFSET_X+ukko.x, MAP_OFFSET_Y+ukko.y,134);
				return;
    		}
            if(ukko.sukupuoli==1 && ukko.laji==8 && ukko.luokka==3)
			{
				glut_drawGraphics(MAP_OFFSET_X+ukko.x, MAP_OFFSET_Y+ukko.y,134);
				return;
			}
            else
			{
				return;
			}
}
