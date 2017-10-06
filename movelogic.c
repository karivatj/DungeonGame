#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#include "game.h"
#include "glut_engine.h"

void liikuta(int cx, int cy) {
    char buf[128];
    int amount;

    switch (ukko.map -> kartta[PAIKKA(cx, cy)]) {
    case 5:
    case 75:
    case 68:
    case 96:
    case 97:
    case 69:
    case 70:
    case 71:
    case 92:
    case 93:
    case 94:
    case 95:
    case 74:
    case 80:
    case 81:
    case 82:
    case 83:
    case 79:
    case 72:
        if (ukko.laji == 3) {
            glut_drawText(0, 0, "This wall is too hard to pass.", 0);
        } else {
            glut_drawText(0, 0, "There is a wall blocking your way.", 0);
        }
        break;
    case 0:
    case 14:
    case 57:
    case 58:
    case 76:
    case 67:
    case 73:
    case 106:
    case 107:
    case 108:
    case 109:
        if (ukko.laji == 3) {
            glut_drawText(0, 0, "Your molecyles are disrupting", 0);
            if (ukko.HP != 0) {
                ukko.HP -= 1;
            }
            ukko.x = cx;
            ukko.y = cy;
        } else {
            glut_drawText(0, 0, "There is a wall blocking your way.", 0);
        }
        break;
    case 63:
    case 64:
    case 65:
    case 66:
        if (ukko.laji == 3) {
            glut_drawText(0, 0, "Your molecyles are disrupting", 0);
            ukko.HP -= 1;
            ukko.x = cx;
            ukko.y = cy;
        } else {
            glut_drawText(0, 0, "There is a bush blocking your way.", 0);
        }
        break;
    case 49:
        if (ukko.laji == 3) {
            glut_drawText(0, 0, "Your molecyles are disrupting", 0);
            ukko.HP -= 1;
            ukko.x = cx;
            ukko.y = cy;
        } else {
            glut_drawText(0, 0, "There is a fountain blocking your way.", 0);
        }
        break;
    case 2:
        if (ukko.laji == 3) {
            glut_drawText(0, 0, "Your molecyles are disrupting", 0);

            ukko.HP -= 1;
            ukko.x = cx;
            ukko.y = cy;
        } else {
            glut_drawText(0, 0, "You opened the door", 0);
            ukko.map -> kartta[PAIKKA(cx, cy)] = 4;
        }
        break;

    case 3:
        if (ukko.map_number == 1) {
            ukko.map_number = 2;
            ukko.map = & kartta_2;
            ukko.x = 14;
            ukko.y = 12;
        }
        break;
    case 6:
        if (ukko.map_number == 2) {
            ukko.map_number = 1;
            ukko.map = & kartta;
            ukko.x = 15;
            ukko.y = 12;
        }
        break;
    case 7:
        if (ukko.punainen_avain == 1) {
            glut_drawText(0, 0, "You used the key and the door opened.", 0);
            ukko.map -> kartta[PAIKKA(cx, cy)] = 4;
            ukko.expo += 2500;
        } else {
            glut_drawText(0, 0, "This door is locked. You need a key to pass.", 0);
        }
        break;
    case 8:
        glut_drawText(0, 0, "You collected a peculiar key.", 0);
        ukko.punainen_avain = 1;
        ukko.map -> kartta[PAIKKA(cx, cy)] = 1;
        ukko.x = cx;
        ukko.y = cy;
        break;
    case 9:
        glut_drawText(0, 0, "You collected an healing potion", 0);
        ukko.pullo += 1;
        ukko.map -> kartta[PAIKKA(cx, cy)] = 1;
        ukko.x = cx;
        ukko.y = cy;
        break;
    case 10:
        if (ukko.keltainen_avain == 1) {
            glut_drawText(0, 0, "You used the key and the door opened.", 0);
            ukko.map -> kartta[PAIKKA(cx, cy)] = 4;
            ukko.expo += 2500;
        } else {
            glut_drawText(0, 0, "This door is locked. You need a key to pass.", 0);
        }
        break;
    case 11:
        glut_drawText(0, 0, "You collected a key.", 0);
        ukko.keltainen_avain = 1;

        ukko.map -> kartta[PAIKKA(cx, cy)] = 1;
        ukko.x = cx;
        ukko.y = cy;

        break;
    case 12:
        if (ukko.map_number == 2) {
            ukko.map_number = 3;
            ukko.map = & kartta_3;
            ukko.x = 5;
            ukko.y = 3;
        }
        break;
    case 13:
        if (ukko.map_number == 3) {
            ukko.map_number = 2;
            ukko.map = & kartta_2;
            ukko.x = 4;
            ukko.y = 3;
        }
        break;
    case 16:
        if (ukko.map_number == 4) {
            ukko.map_number = 2;
            ukko.map = & kartta_2;
        }
        break;
    case 18:
        if (ukko.sininen_avain == 1) {
            glut_drawText(0, 0, "You used the key and the door opened.", 0);
            ukko.map -> kartta[PAIKKA(cx, cy)] = 4;
            ukko.expo += 2500;
        } else {
            glut_drawText(0, 0, "This door is locked. You need a key to pass.", 0);
        }
        break;
    case 19:
        if (ukko.map_number == 2) {
            ukko.map_number = 4;
            ukko.map = & kartta_4;
        }
        break;
    case 20:
        glut_drawText(0, 0, "You collected a key.", 0);
        ukko.sininen_avain = 1;
        ukko.map -> kartta[PAIKKA(cx, cy)] = 1;
        ukko.x = cx;
        ukko.y = cy;
        break;
    case 22:
        if (ukko.map_number == 5) {
            ukko.map_number = 4;

            ukko.map = & kartta_4;
            ukko.x = 29;
            ukko.y = 12;
        }
        break;
    case 23:
        if (ukko.map_number == 4) {
            ukko.map_number = 5;
            ukko.map = & kartta_5;
            ukko.x = 31;
            ukko.y = 12;
        }
        break;
    case 24:
        casino();
        ukko.x = cx;
        ukko.y = cy;
        break;
    case 25:
        pullo_kauppa();
        ukko.x = cx;
        ukko.y = cy;
        break;
    case 27:
        glut_drawText(0, 0, "You cant climb up to mountains", 0);
        break;
    case 28:
        glut_drawText(0, 0, "You are drowning", 0);
        ukko.HP -= 5;
        ukko.x = cx;
        ukko.y = cy;
        break;
    case 29:
        if (ukko.map_number == 6) {
            ukko.map_number = 5;
            ukko.map = & kartta_5;
            ukko.x = 6;
            ukko.y = 1;
        }
        break;
    case 30:
        if (ukko.map_number == 6) {
            ukko.map_number = 7;
            ukko.map = & kartta_7;
            ukko.x = 10;
            ukko.y = 1;
        }
        break;
    case 113:
        if (ukko.map_number == 8) {
            ukko.map_number = 10;
            ukko.map = & kartta_10;
            ukko.x = 1;
            ukko.y = 9;
        }
        break;
    case 114:
        if (ukko.map_number == 10) {
            ukko.map_number = 8;
            ukko.map = & kartta_8;
            ukko.x = 35;
            ukko.y = 10;
        }
        break;
    case 115:
        if (ukko.map_number == 10) {
            ukko.map_number = 11;
            ukko.map = & kartta_11;
            ukko.x = 1;
            ukko.y = 9;
        }
        break;
    case 31:
        if (ukko.map_number == 7) {
            ukko.map_number = 6;
            ukko.map = & kartta_6;
            ukko.x = 9;
            ukko.y = 3;
        }
        break;
    case 32:
        if (ukko.map_number == 7) {
            ukko.map_number = 8;
            ukko.map = & kartta_8;
        }
        break;
    case 33:
        if (ukko.map_number == 8) {
            ukko.map_number = 7;
            ukko.map = & kartta_7;
        }
        break;
    case 35:
        if (ukko.map_number == 1) {
            ukko.map_number = 9;
            ukko.map = & kartta_9;
        }
        break;
    case 36:
        if (ukko.map_number == 5) {
            ukko.map_number = 6;
            ukko.map = & kartta_6;
            ukko.x = 33;
            ukko.y = 3;
        }
        break;
    case 37:
        glut_drawText(0, 0, "This door is locked.", 0);
        break;
    case 40:
        if (ukko.map_number == 6) {
            ukko.map_number = 9;
            ukko.map = & kartta_9;
            ukko.x = 11;
            ukko.y = 4;
        }
        break;
    case 41:
        if (ukko.map_number == 9) {
            ukko.map_number = 6;
            ukko.map = & kartta_6;
            ukko.x = 8;
            ukko.y = 15;
        }

        break;
    case 54:
        amount = rand() % 10 + 5;
        sprintf(buf, "You found some silver worth %d gold pieces", amount);
        glut_drawText(0, 0, buf, 0);
        ukko.raha += amount;
        ukko.map -> kartta[PAIKKA(cx, cy)] = 1;
        ukko.x = cx;
        ukko.y = cy;
        break;
    case 15:
        amount = rand() % 50 + 10;
        sprintf(buf, "You found some gold worth %d gold pieces", amount);
        glut_drawText(0, 0, buf, 0);
        ukko.raha += amount;
        ukko.map -> kartta[PAIKKA(cx, cy)] = 1;
        ukko.x = cx;
        ukko.y = cy;
        break;
    case 55:
        amount = rand() % 100 + 20;
        sprintf(buf, "You found some opals worth %d gold pieces", amount);
        glut_drawText(0, 0, buf, 0);
        ukko.raha += amount;
        ukko.map -> kartta[PAIKKA(cx, cy)] = 1;
        ukko.x = cx;
        ukko.y = cy;
        break;
    case 56:
        amount = rand() % 150 + 30;
        sprintf(buf, "You found some emeralds worth %d gold pieces", amount);
        glut_drawText(0, 0, buf, 0);
        ukko.raha += amount;
        ukko.map -> kartta[PAIKKA(cx, cy)] = 1;
        ukko.x = cx;
        ukko.y = cy;
        break;
    case 53:
        amount = rand() % 200 + 40;
        sprintf(buf, "You found some adamantium worth %d gold pieces", amount);
        glut_drawText(0, 0, buf, 0);
        ukko.raha += amount;
        ukko.map -> kartta[PAIKKA(cx, cy)] = 1;
        ukko.x = cx;
        ukko.y = cy;
        break;
    case 84:
        glut_drawText(0, 0, "The lava burns you", 0);
        ukko.HP -= 20;
        ukko.x = cx;
        ukko.y = cy;
        break;

    case 85:
        glut_drawText(0, 0, "The lava burns you", 0);

        ukko.HP -= 15;
        ukko.x = cx;
        ukko.y = cy;
        break;
    case 86:
        glut_drawText(0, 0, "The lava burns you", 0);

        ukko.HP -= 10;
        ukko.x = cx;
        ukko.y = cy;
        break;
    case 116:
        if (ukko.map_number == 11) {

            ukko.map_number = 10;
            ukko.map = & kartta_10;
            ukko.x = 35;
            ukko.y = 8;
        }

        break;
    case 117:
        if (ukko.map_number == 11) {
            ukko.map_number = 12;
            ukko.map = & kartta_12;
        }
        ukko.x = 1;
        ukko.y = 9;
        break;
    case 118:
        if (ukko.map_number == 12) {
            ukko.map_number = 11;
            ukko.map = & kartta_11;
            ukko.x = 35;
            ukko.y = 8;
        }
        break;
    case 119:
        if (ukko.map_number == 12)

        {
            ukko.map_number = 5;
            ukko.map = & kartta_5;
            ukko.x = 12;
            ukko.y = 15;
        }
        break;
    case 120:
        if (ukko.map_number == 5) {
            ukko.map_number = 12;
            ukko.map = & kartta_12;
            ukko.x = 26;
            ukko.y = 3;
        }
        break;
    case 100:
        if (ukko.map_number == 6) {
            ukko.map_number = 13;
            ukko.map = & kartta_13;
            ukko.x = 9;
            ukko.y = 17;
        }
        break;
    case 103:
        if (ukko.map_number == 13) {
            ukko.map_number = 6;
            ukko.map = & kartta_6;
            ukko.x = 10;
            ukko.y = 1;
        }
        break;
    default:
        ukko.x = cx;
        ukko.y = cy;
        break;
    }
}
