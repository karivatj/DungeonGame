
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#include "game.h"
#include "glut_engine.h"

TAVARA tavara_taulu[] = {
	{ "Steel dagger(s)", 150, 0, 4, 0, 0, 0, 0, 0, 0, 0,0 ,0 ,0,0 }
};

ARTIFACT tavara_taulu_2[] = {
	{ "The Long Sword 'Ringil'", 700, 15, 100, STATUS_BRAND_JAA && STATUS_RES_JAA && STATUS_RES_VALO , 10, 24, 19, 0,0,0,0,0,0,0}
};

RUOKA tavara_taulu_3[] = {
	{" ", -1,-1,-1,-1,-1,-1,-1,-1,-1}
};
