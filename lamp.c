
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#include "game.h"
#include "glut_engine.h"

#include "GL/glut.h"


void lamppu (int lamppu)
{
	int i, j;

	if(lamppu == 1)
	{
	for (i=0; i<3; i++)
	{
		for (j=0; j<3; j++)
		{
			ukko.map->hidden[PAIKKA(ukko.x-1+i, ukko.y-1+j)] = 1;
		}
	}
	}
	if(lamppu == 2)
	{

		for (i=0; i<3; i++)
	{
		for (j=0; j<3; j++)
	{
			ukko.map->hidden[PAIKKA(ukko.x-1+i, ukko.y-1+j)] = 1;
	}
		}

	if ((ukko.map->kartta[PAIKKA(ukko.x+1, ukko.y)] != 0) &&
		(ukko.map->kartta[PAIKKA(ukko.x+1, ukko.y)] != 5) &&
		(ukko.map->kartta[PAIKKA(ukko.x+1, ukko.y)] != 2) &&
		(ukko.map->kartta[PAIKKA(ukko.x+1, ukko.y)] != 36) &&
		(ukko.map->kartta[PAIKKA(ukko.x+1, ukko.y)] != 75) &&
		(ukko.map->kartta[PAIKKA(ukko.x+1, ukko.y)] != 68) &&
		(ukko.map->kartta[PAIKKA(ukko.x+1, ukko.y)] != 96) &&
		(ukko.map->kartta[PAIKKA(ukko.x+1, ukko.y)] != 97) &&
		(ukko.map->kartta[PAIKKA(ukko.x+1, ukko.y)] != 69) &&
		(ukko.map->kartta[PAIKKA(ukko.x+1, ukko.y)] != 70) &&
		(ukko.map->kartta[PAIKKA(ukko.x+1, ukko.y)] != 71) &&
		(ukko.map->kartta[PAIKKA(ukko.x+1, ukko.y)] != 92) &&
		(ukko.map->kartta[PAIKKA(ukko.x+1, ukko.y)] != 93) &&
		(ukko.map->kartta[PAIKKA(ukko.x+1, ukko.y)] != 94) &&
		(ukko.map->kartta[PAIKKA(ukko.x+1, ukko.y)] != 74) &&
		(ukko.map->kartta[PAIKKA(ukko.x+1, ukko.y)] != 80) &&
		(ukko.map->kartta[PAIKKA(ukko.x+1, ukko.y)] != 81) &&
		(ukko.map->kartta[PAIKKA(ukko.x+1, ukko.y)] != 82) &&
		(ukko.map->kartta[PAIKKA(ukko.x+1, ukko.y)] != 83) &&
		(ukko.map->kartta[PAIKKA(ukko.x+1, ukko.y)] != 79) &&
		(ukko.map->kartta[PAIKKA(ukko.x+1, ukko.y)] != 14) &&
		(ukko.map->kartta[PAIKKA(ukko.x+1, ukko.y)] != 106) &&
		(ukko.map->kartta[PAIKKA(ukko.x+1, ukko.y)] != 107) &&
		(ukko.map->kartta[PAIKKA(ukko.x+1, ukko.y)] != 108) &&
		(ukko.map->kartta[PAIKKA(ukko.x+1, ukko.y)] != 109) &&
		(ukko.map->kartta[PAIKKA(ukko.x+1, ukko.y)] != 72))
	{
		for (i=0; i<3; i++)
		{
			ukko.map->hidden[PAIKKA(ukko.x+2, ukko.y-1+i)] = 1;
		}
	}

		if((ukko.map->kartta[PAIKKA(ukko.x-1, ukko.y)] != 0) &&
		(ukko.map->kartta[PAIKKA(ukko.x-1, ukko.y)] != 5) &&
		(ukko.map->kartta[PAIKKA(ukko.x-1, ukko.y)] != 2) &&
		(ukko.map->kartta[PAIKKA(ukko.x-1, ukko.y)] != 36) &&
		(ukko.map->kartta[PAIKKA(ukko.x-1, ukko.y)] != 75) &&
		(ukko.map->kartta[PAIKKA(ukko.x-1, ukko.y)] != 68) &&
		(ukko.map->kartta[PAIKKA(ukko.x-1, ukko.y)] != 96) &&
		(ukko.map->kartta[PAIKKA(ukko.x-1, ukko.y)] != 97) &&
		(ukko.map->kartta[PAIKKA(ukko.x-1, ukko.y)] != 69) &&
		(ukko.map->kartta[PAIKKA(ukko.x-1, ukko.y)] != 70) &&
		(ukko.map->kartta[PAIKKA(ukko.x-1, ukko.y)] != 71) &&
		(ukko.map->kartta[PAIKKA(ukko.x-1, ukko.y)] != 92) &&
		(ukko.map->kartta[PAIKKA(ukko.x-1, ukko.y)] != 93) &&
		(ukko.map->kartta[PAIKKA(ukko.x-1, ukko.y)] != 94) &&
		(ukko.map->kartta[PAIKKA(ukko.x-1, ukko.y)] != 74) &&
		(ukko.map->kartta[PAIKKA(ukko.x-1, ukko.y)] != 80) &&
		(ukko.map->kartta[PAIKKA(ukko.x-1, ukko.y)] != 81) &&
		(ukko.map->kartta[PAIKKA(ukko.x-1, ukko.y)] != 82) &&
		(ukko.map->kartta[PAIKKA(ukko.x-1, ukko.y)] != 83) &&
		(ukko.map->kartta[PAIKKA(ukko.x-1, ukko.y)] != 79) &&
		(ukko.map->kartta[PAIKKA(ukko.x-1, ukko.y)] != 14) &&
		(ukko.map->kartta[PAIKKA(ukko.x-1, ukko.y)] != 106) &&
		(ukko.map->kartta[PAIKKA(ukko.x-1, ukko.y)] != 107) &&
		(ukko.map->kartta[PAIKKA(ukko.x-1, ukko.y)] != 108) &&
		(ukko.map->kartta[PAIKKA(ukko.x-1, ukko.y)] != 109) &&
		(ukko.map->kartta[PAIKKA(ukko.x-1, ukko.y)] != 72))
	{
		for (i=0; i<3; i++)
		{
			ukko.map->hidden[PAIKKA(ukko.x-2, ukko.y-1+i)] = 1;
		}
	}

		if ((ukko.map->kartta[PAIKKA(ukko.x, ukko.y-1)] != 0) &&
		(ukko.map->kartta[PAIKKA(ukko.x, ukko.y-1)] != 5) &&
		(ukko.map->kartta[PAIKKA(ukko.x, ukko.y-1)] != 2) &&
		(ukko.map->kartta[PAIKKA(ukko.x, ukko.y-1)] != 36) &&
		(ukko.map->kartta[PAIKKA(ukko.x, ukko.y-1)] != 75) &&
		(ukko.map->kartta[PAIKKA(ukko.x, ukko.y-1)] != 68) &&
		(ukko.map->kartta[PAIKKA(ukko.x, ukko.y-1)] != 96) &&
		(ukko.map->kartta[PAIKKA(ukko.x, ukko.y-1)] != 97) &&
		(ukko.map->kartta[PAIKKA(ukko.x, ukko.y-1)] != 69) &&
		(ukko.map->kartta[PAIKKA(ukko.x, ukko.y-1)] != 70) &&
		(ukko.map->kartta[PAIKKA(ukko.x, ukko.y-1)] != 71) &&
		(ukko.map->kartta[PAIKKA(ukko.x, ukko.y-1)] != 92) &&
		(ukko.map->kartta[PAIKKA(ukko.x, ukko.y-1)] != 93) &&
		(ukko.map->kartta[PAIKKA(ukko.x, ukko.y-1)] != 94) &&
		(ukko.map->kartta[PAIKKA(ukko.x, ukko.y-1)] != 74) &&
		(ukko.map->kartta[PAIKKA(ukko.x, ukko.y-1)] != 80) &&
		(ukko.map->kartta[PAIKKA(ukko.x, ukko.y-1)] != 81) &&
		(ukko.map->kartta[PAIKKA(ukko.x, ukko.y-1)] != 82) &&
		(ukko.map->kartta[PAIKKA(ukko.x, ukko.y-1)] != 83) &&
		(ukko.map->kartta[PAIKKA(ukko.x, ukko.y-1)] != 79) &&
		(ukko.map->kartta[PAIKKA(ukko.x, ukko.y-1)] != 14) &&
		(ukko.map->kartta[PAIKKA(ukko.x, ukko.y-1)] != 106) &&
		(ukko.map->kartta[PAIKKA(ukko.x, ukko.y-1)] != 107) &&
		(ukko.map->kartta[PAIKKA(ukko.x, ukko.y-1)] != 108) &&
		(ukko.map->kartta[PAIKKA(ukko.x, ukko.y-1)] != 109) &&
		(ukko.map->kartta[PAIKKA(ukko.x, ukko.y-1)] != 72))
	{
		for (i=0; i<3; i++)
		{
			ukko.map->hidden[PAIKKA(ukko.x-1+i, ukko.y-2)] = 1;
		}
	}

		if ((ukko.map->kartta[PAIKKA(ukko.x, ukko.y+1)] != 0) &&
		(ukko.map->kartta[PAIKKA(ukko.x, ukko.y+1)] != 5) &&
		(ukko.map->kartta[PAIKKA(ukko.x, ukko.y+1)] != 2) &&
		(ukko.map->kartta[PAIKKA(ukko.x, ukko.y+1)] != 36) &&
		(ukko.map->kartta[PAIKKA(ukko.x, ukko.y+1)] != 75) &&
		(ukko.map->kartta[PAIKKA(ukko.x, ukko.y+1)] != 68) &&
		(ukko.map->kartta[PAIKKA(ukko.x, ukko.y+1)] != 96) &&
		(ukko.map->kartta[PAIKKA(ukko.x, ukko.y+1)] != 97) &&
		(ukko.map->kartta[PAIKKA(ukko.x, ukko.y+1)] != 69) &&
		(ukko.map->kartta[PAIKKA(ukko.x, ukko.y+1)] != 70) &&
		(ukko.map->kartta[PAIKKA(ukko.x, ukko.y+1)] != 71) &&
		(ukko.map->kartta[PAIKKA(ukko.x, ukko.y+1)] != 92) &&
		(ukko.map->kartta[PAIKKA(ukko.x, ukko.y+1)] != 93) &&
		(ukko.map->kartta[PAIKKA(ukko.x, ukko.y+1)] != 94) &&
		(ukko.map->kartta[PAIKKA(ukko.x, ukko.y+1)] != 74) &&
		(ukko.map->kartta[PAIKKA(ukko.x, ukko.y+1)] != 80) &&
		(ukko.map->kartta[PAIKKA(ukko.x, ukko.y+1)] != 81) &&
		(ukko.map->kartta[PAIKKA(ukko.x, ukko.y+1)] != 82) &&
		(ukko.map->kartta[PAIKKA(ukko.x, ukko.y+1)] != 83) &&
		(ukko.map->kartta[PAIKKA(ukko.x, ukko.y+1)] != 79) &&
		(ukko.map->kartta[PAIKKA(ukko.x, ukko.y+1)] != 14) &&
		(ukko.map->kartta[PAIKKA(ukko.x, ukko.y+1)] != 106) &&
		(ukko.map->kartta[PAIKKA(ukko.x, ukko.y+1)] != 107) &&
		(ukko.map->kartta[PAIKKA(ukko.x, ukko.y+1)] != 108) &&
		(ukko.map->kartta[PAIKKA(ukko.x, ukko.y+1)] != 109) &&
		(ukko.map->kartta[PAIKKA(ukko.x, ukko.y+1)] != 72))
	{
		for (i=0; i<3; i++)
		{
			ukko.map->hidden[PAIKKA(ukko.x-1+i, ukko.y+2)] = 1;
		}
	}
		}





}
