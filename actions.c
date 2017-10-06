#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#include "game.h"
#include "glut_engine.h"

void oven_sulkeminen(void) {
    glut_drawText(0, 0, "Close door, which direction?", 0);
    glut_redraw();
    tila = TILA_OVENSULKEMINEN;
}
void oven_sulkeminen_tarkistus(int cx, int cy) {
    switch (ukko.map -> kartta[PAIKKA(cx, cy)]) {
    case 4:
        glut_drawText(0, 0, "You closed the door.", 0);
        ukko.map -> kartta[PAIKKA(cx, cy)] = 2;
        break;
    case 2:
        glut_drawText(0, 0, "The door was already closed.", 0);
        break;
    case 87:
        glut_drawText(0, 0, "The door is broken.", 0);
        break;
    default:
        glut_drawText(0, 0, "You see nothing there to close.", 0);
        break;
    }
}
void oven_avaus(void) {
    glut_drawText(0, 0, "Open door, which direction?", 0);
    glut_redraw();
    tila = TILA_OVENAVAUS;
}
void oven_avaus_tarkistus(int cx, int cy) {
    switch (ukko.map -> kartta[PAIKKA(cx, cy)]) {
    case 2:
        glut_drawText(0, 0, "You opened the door.", 0);
        ukko.map -> kartta[PAIKKA(cx, cy)] = 4;
        break;
    case 21:
        glut_drawText(0, 0, "This door is locked.", 0);
        break;
    case 38:
        glut_drawText(0, 0, "This door is broken.", 0);
        break;
    case 7:
        glut_drawText(0, 0, "This door is locked. You need red key to pass.", 0);
        ukko.map -> kartta[PAIKKA(cx, cy)] = 7;
        if (ukko.punainen_avain == 1) {
            glut_drawText(0, 0, "You used the key and the door opened.", 0);
            ukko.punainen_avain = 0;
            ukko.map -> kartta[PAIKKA(cx, cy)] = 4;
            ukko.expo += 2500;
        }
        break;
    case 10:
        glut_drawText(0, 0, "This door is locked. You need a yellow key to pass.", 0);
        if (ukko.keltainen_avain == 1) {
            glut_drawText(0, 0, "You used the key and the door opened.", 0);
            ukko.keltainen_avain = 0;
            ukko.map -> kartta[PAIKKA(cx, cy)] = 4;
            ukko.expo += 2500;
        }
        break;

    case 18:
        glut_drawText(0, 0, "This door is locked. You need a key to pass.", 0);
        if (ukko.sininen_avain == 1) {
            glut_drawText(0, 0, "You used the key and the door opened.", 0);
            ukko.sininen_avain = 0;
            ukko.map -> kartta[PAIKKA(cx, cy)] = 4;
            ukko.expo += 2500;
        }
        break;
    default:
        glut_drawText(0, 0, "You see nothing there to open.", 0);
        break;
    }
}
void kaivaminen(void) {
    glut_drawText(0, 0, "Tunnel, which direction:", 0);
    tila = TILA_KAIVAMINEN;
}
void kaivamis_tarkistus(int cx, int cy) {
    int wall;
    int treasure;
    switch (ukko.map -> kartta[PAIKKA(cx, cy)]) {
    case 0:
        if (ukko.voima >= 18) {
            glut_drawText(0, 0, "The wall deteriorates as you dig through it.", 0);
            ukko.map -> kartta[PAIKKA(cx, cy)] = 106;
        } else {
            glut_drawText(0, 0, "The wall resist your attack.", 0);
            ukko.map -> kartta[PAIKKA(cx, cy)] = 0;
        }
        break;
    case 57:
        if (ukko.voima > 18) {
            glut_drawText(0, 0, "The wall deteriorates as you dig through it.", 0);
            ukko.map -> kartta[PAIKKA(cx, cy)] = 1;
        } else {
            glut_drawText(0, 0, "The wall resist your attack.", 0);
            ukko.map -> kartta[PAIKKA(cx, cy)] = 0;
        }
        break;
    case 106:
        if (ukko.voima >= 14) {
            glut_drawText(0, 0, "The wall deteriorates as you dig through it.", 0);
            wall = rand() % 5;

            if (wall == 0 || wall == 2)
                ukko.map -> kartta[PAIKKA(cx, cy)] = 107;
            else if (wall == 1 || wall == 3)
                ukko.map -> kartta[PAIKKA(cx, cy)] = 108;
            else if (wall == 4 || wall == 5)
                ukko.map -> kartta[PAIKKA(cx, cy)] = 109;
        } else {
            glut_drawText(0, 0, "The wall resist your attack.", 0);
            ukko.map -> kartta[PAIKKA(cx, cy)] = 106;
        }
        break;
    case 107:
    case 108:
    case 109:
        if (ukko.voima >= 5) {
            glut_drawText(0, 0, "You managed to dig through the wall.", 0);
            ukko.map -> kartta[PAIKKA(cx, cy)] = 1;
        } else {
            glut_drawText(0, 0, "The wall resist your attack.", 0);
            ukko.map -> kartta[PAIKKA(cx, cy)] = 107;
        }
        break;
    case 4:
    case 1:
        glut_drawText(0, 0, "There is no wall in that direction!", 0);
        break;
    case 2:
    case 6:
        if (ukko.voima > 3) {
            glut_drawText(0, 0, "You broke through the door.", 0);
            ukko.map -> kartta[PAIKKA(cx, cy)] = 38;
        } else {
            glut_drawText(0, 0, "The door resists your attack.", 0);
            ukko.map -> kartta[PAIKKA(cx, cy)] = 6;
        }
        break;
    case 5:
    case 58:
    case 75:
    case 76:
    case 67:
    case 68:
    case 73:
    case 69:
    case 70:
    case 71:
    case 92:
    case 93:
    case 94:
    case 95:
    case 80:
    case 81:
    case 82:
    case 83:
    case 74:
    case 96:
    case 97:
        glut_drawText(0, 0, "This seems to be permanent rock.", 0);
        break;
    case 36:
        glut_drawText(0, 0, "The door is already broken.", 0);
        break;
    case 14:
        if (ukko.voima > 16) {
            glut_drawText(0, 0, "You managed to dig out some valuable ore!", 0);
            treasure = rand() % 4;
            if (treasure == 0)
                ukko.map -> kartta[PAIKKA(cx, cy)] = 15;
            else if (treasure == 1)
                ukko.map -> kartta[PAIKKA(cx, cy)] = 53;
            else if (treasure == 2)
                ukko.map -> kartta[PAIKKA(cx, cy)] = 54;
            else if (treasure == 3)
                ukko.map -> kartta[PAIKKA(cx, cy)] = 55;
            else if (treasure == 4)
                ukko.map -> kartta[PAIKKA(cx, cy)] = 56;
        } else {
            glut_drawText(0, 0, "Your efforts are not strong enough to dig out the ore.", 0);
            ukko.map -> kartta[PAIKKA(cx, cy)] = 14;
        }
        break;
    case 7:
    case 10:
        glut_drawText(0, 0, "This door is too hard to tunnel.", 0);
        break;
    }
}
