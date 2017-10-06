#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#include "game.h"
#include "glut_engine.h"

void help(void)
{
    FILE *tiedosto;
    int merkki;

    tiedosto = fopen ("Help.txt", "r");
    if(tiedosto == NULL)
    {
        printf("Couldn't open Help.txt\n");
        tila=TILA_NORMAALI;
    }

    merkki = fgetc (tiedosto);
    while (merkki != EOF)
    {
        printf ("%c", merkki);
        merkki = fgetc (tiedosto);
    }
    fclose (tiedosto);
}
