#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#include "game.h"
#include "glut_engine.h"

#include "GL/glut.h"

UKKO ukko;
TILA tila = TILA_NORMAALI;

void kari_mouse_handler(int button, int state, int x, int y) {

}

void kari_key_handler(int key, int x, int y) {
    glut_clearScreen();
    lamppu(ukko.lamppu);
    nappulan_tarkistus(key);
    redraw_Screen();
}

void main_menu(int value) {
    switch (value) {
    case 1:
        glut_clearScreen();
        tila = TILA_UKONKYSELY1;
        redraw_Screen();
        break;
    case 2:
        glut_ChangeTileSet(8);
        redraw_Screen();
        break;
    case 3:
        glut_ChangeTileSet(16);
        redraw_Screen();
        break;
    case 4:
        glut_ChangeTileSet(32);
        redraw_Screen();
        break;
    case 666:
        glut_quit();
        break;
    }
}
void redraw_Screen(void) {

    if (ukko.HP < 0) {
        glut_drawText(0, 0, "You died...", 0);
        kuolema();
    } else {
        switch (tila) {
        case TILA_ALOITUS:
            sponsori();
            break;
        case TILA_UKONKYSELY1:
            sukupuoli();
            break;
        case TILA_UKONKYSELY2:
            laji();
            break;
        case TILA_UKONKYSELY3:
            luokka();
            break;
        case TILA_KASINO:
            casino();
            break;
        case TILA_PULLOKAUPPA:
            pullo_kauppa();
            break;
        case TILA_INVENTAARIO:
            inventoori();
            break;
        default:
            kartan_piirto();
            switch (ukko.map_number) {
            case 1:
                glut_drawText(39, MAP_OFFSET_Y + 30, "Floor 3", 1);
                break;
            case 2:
                glut_drawText(39, MAP_OFFSET_Y + 30, "Floor 2", 1);
                break;
            case 3:
                glut_drawText(39, MAP_OFFSET_Y + 30, "Floor 4", 1);
                break;
            case 4:
                glut_drawText(39, MAP_OFFSET_Y + 30, "Floor 1", 1);
                break;
            case 5:
                glut_drawText(39, MAP_OFFSET_Y + 30, "Outpost", 1);
                break;
            case 6:
                glut_drawText(39, MAP_OFFSET_Y + 30, "World Map", 1);
                break;
            case 7:
                glut_drawText(39, MAP_OFFSET_Y + 30, "Angwil", 1);
                break;
            case 8:
                glut_drawText(39, MAP_OFFSET_Y + 30, "Sewer", 1);
                break;
            case 9:
                glut_drawText(39, MAP_OFFSET_Y + 30, "Wilderness", 1);
                break;
            default:
                glut_drawText(40, MAP_OFFSET_Y + 30, "Unknown", 1);
                break;
            }
            break;
        }
    }

    glut_redraw();
}

void kari_init_handler(void) {
    ukko.sukupuoli = 0;
    ukko.laji = 0;
    ukko.luokka = 0;
    ukko.x = 4;
    ukko.y = 2;
    ukko.lamppu = 2;
    ukko.hinta = rand() % 600 + 500;
    ukko.AC = 0;
    ukko.HP = rand() % 20 + 10;
    ukko.maxHP = ukko.HP;
    ukko.voima = 18; //rand()%18 + 3;
    ukko.ketteryys = rand() % 18 + 3;
    ukko.alykkyys = rand() % 18 + 3;
    ukko.viisaus = rand() % 18 + 3;
    ukko.kestavyys = rand() % 18 + 3;
    ukko.charisma = rand() % 18 + 3;
    ukko.second = 1;
    ukko.minute = 32;
    ukko.hour = 17;
    ukko.day = 14;
    ukko.month = 8;
    ukko.ravinto = 10000;
    ukko.raha = 0;
    ukko.year = 1352;
    ukko.moves = 0;
    ukko.curse = 0;
    ukko.map = & kartta;
    ukko.map_number = 1;
    ukko.pullo = 0;
    ukko.mana = 0;
    ukko.maxmana = ukko.mana;
    ukko.punainen_avain = 0;
    ukko.keltainen_avain = 0;
    ukko.expo = 0;
    ukko.level = 1;
    ukko.sininen_avain = 0;
    ukko.kaupan_pullo = 9;
    ukko.raha_maara = rand() % 49 + 1;

    memset(ukko.inventaario, 0, sizeof(ukko.inventaario));
    ukko.inventaario[0].used = 1;
    ukko.inventaario[0].amount = 1;
    ukko.inventaario[0].index = 1;

    ukko.inventaario[1].used = 1;
    ukko.inventaario[1].amount = 5;
    ukko.inventaario[1].index = 0;

    glutCreateMenu(main_menu);
    glutAddMenuEntry("New", 1);
    glutAddMenuEntry("Quit", 666);
    glutAddMenuEntry("8x8", 2);
    glutAddMenuEntry("16x16", 3);
    glutAddMenuEntry("32x32", 4);

    glutAttachMenu(GLUT_RIGHT_BUTTON); {
        extern int glut_window;
        glutSetWindow(glut_window);
    }

    glutAttachMenu(GLUT_RIGHT_BUTTON);
    sponsori();
}

void kari_cleanup_handler(void) {

}

void kartan_piirto(void) {

    int cx, cy;

    for (cy = 0; cy < KARTTA1_Y; cy++) {
        for (cx = 0; cx < KARTTA1_X; cx++) {
            if (ukko.map -> hidden[PAIKKA(cx, cy)] == 1) {
                glut_drawGraphics(MAP_OFFSET_X + cx, MAP_OFFSET_Y + cy, ukko.map -> kartta[PAIKKA(cx, cy)]);
            }
        }
    }

    glut_toggleBlending();
    aija();
    glut_toggleBlending();

    #if 1
    char buf[64];
    sprintf(buf, "%s", get_species());
    glut_drawText(1, MAP_OFFSET_Y, buf, 0);

    sprintf(buf, "%s", get_class());
    glut_drawText(1, MAP_OFFSET_Y + 1, buf, 0);

    sprintf(buf, "Lev: %d", ukko.level);
    glut_drawText(1, MAP_OFFSET_Y + 2, buf, 0);

    sprintf(buf, "Exp: %d", ukko.expo);
    glut_drawText(1, MAP_OFFSET_Y + 3, buf, 0);

    sprintf(buf, "AU:  %d", ukko.raha);
    glut_drawText(1, MAP_OFFSET_Y + 4, buf, 0);

    sprintf(buf, "Str: %d", ukko.voima);
    glut_drawText(1, MAP_OFFSET_Y + 6, buf, 0);

    sprintf(buf, "Int: %d", ukko.alykkyys);
    glut_drawText(1, MAP_OFFSET_Y + 7, buf, 0);

    sprintf(buf, "Wis: %d", ukko.viisaus);
    glut_drawText(1, MAP_OFFSET_Y + 8, buf, 0);

    sprintf(buf, "Dex: %d", ukko.ketteryys);
    glut_drawText(1, MAP_OFFSET_Y + 9, buf, 0);

    sprintf(buf, "Con: %d", ukko.kestavyys);
    glut_drawText(1, MAP_OFFSET_Y + 10, buf, 0);

    sprintf(buf, "Chr: %d", ukko.charisma);
    glut_drawText(1, MAP_OFFSET_Y + 11, buf, 0);

    sprintf(buf, "Max HP: %d", ukko.maxHP);
    glut_drawText(1, MAP_OFFSET_Y + 13, buf, 0);

    sprintf(buf, "Cur HP: %d", ukko.HP);
    glut_drawText(1, MAP_OFFSET_Y + 14, buf, 0);

    sprintf(buf, "Time: %d:%d", ukko.hour, ukko.minute);
    glut_drawText(1, MAP_OFFSET_Y + 30, buf, 1);

    food_status(ukko.ravinto);
    #endif
}

void kuolema(void) {
    char buf[128];
    glut_clearScreen();
    glut_drawText(9, 2, "                YOU DIED                           ", 0);
    glut_drawText(9, 3, "                                                   ", 0);
    glut_drawText(9, 4, "             _______________                            ", 0);
    glut_drawText(9, 5, "            /               \\        ___               ", 0);
    glut_drawText(9, 6, "           /                 \\___   /   \\       ___   ", 0);
    glut_drawText(9, 7, "  ___     /        RIP        \\  \\  :   :      /   \\ ", 0);
    glut_drawText(9, 8, " /   \\   /                     \\ : _;,,,;_     :   :   ", 0);

    glut_drawText(9, 9, " :   :  |                       |;_           _;,,,;_   ", 0);
    glut_drawText(9, 10, "_;,,,;_ |                       |   ___                 ", 0);
    glut_drawText(9, 11, "        |          DIED         |  /   \\               ", 0);
    glut_drawText(9, 12, "        |                       |  :   :                ", 0);
    sprintf(buf, "        |     Level:  %2d        | _;,,,;_   ____", ukko.level);
    glut_drawText(9, 13, buf, 0);
    sprintf(buf, "        |     EXP: %5d        |          /    \\", ukko.expo);
    glut_drawText(9, 14, buf, 0);
    sprintf(buf, "        |     AU:%7d        |          :    : ", ukko.raha);
    glut_drawText(9, 15, buf, 0);
    glut_drawText(9, 16, "  ___   |     Name:             |          :    : ", 0);
    glut_drawText(9, 17, " /   \\  |                       |         _;,,,,;_", 0);
    glut_drawText(9, 18, " :   :  |    Time Of Death      |                 ", 0);
    glut_drawText(9, 19, "_;,,,;_ |                       |                 ", 0);
    glut_drawText(9, 20, "        |                       |                 ", 0);
    glut_drawText(9, 21, " *  *  *|   *     *     *    *  |** *    *        ", 0);
    glut_drawText(9, 22, "_\\/(__)/\\_)_/___(\\/___(_\\)/_\\__\\(/_|_)__    ", 0);
    glut_drawText(9, 23, "Press any button to continue. (too bad)             ", 0);
    tila = TILA_KUOLEMA;
}

void food_status(int status) {

    if(tila == TILA_NORMAALI) {
        energian_piirto(ukko.HP);
        if (status > 10000) {
            glut_drawText(1, 22, "Gorged", 0);
        }
        if (status <= 10000 && status >= 8000) {
            glut_drawText(1, 22, "Full", 0);
        }
        if (status < 8000 && status >= 1000) {
            glut_drawText(1, 22, "    ", 0);
        }
        if (status < 1000 && status >= 500) {
            glut_drawText(1, 22, "Hungry", 0);
        }
        if (status < 500 && status > 0) {
            glut_drawText(1, 22, "Weak", 0);
        }
        if (status <= 0) {
            glut_drawText(1, 22, "Starving", 0);
            ukko.HP -= 1;
        }
    }
}

void tarkista_siirto(void) {

    memset(ukko.map -> hidden, 0, sizeof(ukko.map -> hidden));
    lamppu(ukko.lamppu);

    ukko.ravinto -= RUOAN_SULATUS;
    ukko.second += AIKA_SIIRROS;

    if (ukko.expo >= ukko.level * 7500) {
        if (ukko.level < 50) {
            glut_drawText(0, 0, "LEVEL UP", 0);
            ukko.level += 1;
            ukko.maxHP += 10;
            ukko.HP += 10;
        }
    }
    if (ukko.map_number == 6) {
        ukko.second += AIKA_SIIRROS_2;
        ukko.ravinto -= RUOAN_SULATUS_2;
    }
    if (ukko.moves % 10 == 0) {
        if (ukko.HP < ukko.maxHP)
            UKKO_HP(+1);
    }

    if (ukko.moves % 1 == 0) {
        if (ukko.HP > ukko.maxHP)
            UKKO_HP(-1);
    }
    if (ukko.second > 60) {
        ukko.second %= 60;
        ukko.minute += 1;
    }
    if (ukko.minute > 60) {
        ukko.minute = 1;
        ukko.hour += 1;
    }
    if (ukko.hour > 24)

    {
        ukko.hour = 1;
        ukko.day += 1;
    }
    if (ukko.day > 30) {
        ukko.month += 1;
        ukko.day = 1;
    }
    if (ukko.month > 12) {
        ukko.month = 1;
        ukko.year += 1;
    }
    if (ukko.curse == 1) {
        if (ukko.moves % 10 == 0) {
            glut_drawText(0, 0, "Voice booms in your mind: DIE MORTAL! Lightning strikes at you!", 0);
            UKKO_HP(-rand() % 20);
        }
    }
}

void juonti(void) {
    char buf[128];
    glut_drawText(0, 0, "Choose a bottle to drink.", 0);
    sprintf(buf, "a) %d Potion(s) of Healing", ukko.pullo);
    glut_drawText(0, 1, buf, 0);
    glut_drawText(0, 2, "b) -----------------", 0);
    glut_drawText(0, 3, "c) -----------------", 0);
    tila = TILA_JUONTI;

}
void inventoori(void) {
    char buf[512];
    int i;

    i = 0;

    while (ukko.inventaario[i].used != 0) {
        sprintf(buf, "%d) %d %s", i, ukko.inventaario[i].amount,
            tavara_taulu[ukko.inventaario[i].index].nimi);
        glut_drawText(2, i, buf, 0);
        i++;
    }

    if (i == 0) {
        glut_drawText(1, 1, "Inventory empty, press ESC to exit", 1);
    }

    tila = TILA_INVENTAARIO;
}
void pudota_tavara(int cx, int cy) {

}
void sponsori(void) {
    glut_drawText(11, 6, "Press right mouse button to open the menu", 1);
    tila = TILA_ALOITUS;
}
void casino(void) {
    glut_drawText(0, 3, " Colleuse (Dwarf)                  *CASINO*", 0);
    glut_drawText(0, 28, " GAMES:", 0);
    glut_drawText(0, 31, " a) Play dice slots         b) Spin the Wheel", 0);
    glut_drawText(0, 33, " ESC) Exit the building", 0);
    tila = TILA_KASINO;
}

void pullo_kauppa(void) {

    char buf[128];
    glut_drawText(0, 3, "          Dridash the Alchemist (Half-orc)       Alchemy Shop", 0);
    glut_drawText(0, 6, "    Item Description                            Price", 0);
    sprintf(buf, " a) %2d Potion(s) of Healing                       %3d", ukko.kaupan_pullo, ukko.hinta);
    glut_drawText(0, 7, buf, 0);
    glut_drawText(0, 8, " ESC) Exit building", 0);
    sprintf(buf, " Gold remaining %5d", ukko.raha);
    glut_drawText(25, 25, buf, 0);
    tila = TILA_PULLOKAUPPA;
}
void itse_murha(void) {
    glut_drawText(0, 0, "Do you really want to commit a suicide? [y/n]", 0);
    tila = TILA_ITSEMURHA;
}
void itse_murha_tarkistus(void) {
    glut_drawText(0, 0, "Please verify SUICIDE by typing the '@' sign:", 0);
    tila = TILA_ITSEMURHA_TARKISTUS;
}
void sukupuoli(void) {
    glut_drawText(2, 28, "Please answer the following questions. Most of the questions", 0);
    glut_drawText(2, 29, "display a set of standard answers and many will also accept", 0);
    glut_drawText(2, 30, "some special responses, including 'Q' to quit, 'S' to restart", 0);
    glut_drawText(2, 31, "and 'R' for random.", 0);
    glut_drawText(2, 32, "Your 'sex' does not have any significant gameplay effects.", 0);
    glut_drawText(2, 34, "Choose a Sex (a-b)", 0);
    glut_drawText(2, 35, "a) Female b) Male", 0);
    tila = TILA_UKONKYSELY1;
}
void laji(void) {
    glut_drawText(2, 28, "Please answer the following questions. Most of the questions", 0);
    glut_drawText(2, 29, "display a set of standard answers and many will also accept", 0);
    glut_drawText(2, 30, "some special responses, including 'Q' to quit, 'S' to restart", 0);
    glut_drawText(2, 31, "and 'R' for random.", 0);
    glut_drawText(2, 32, "Your 'race' determines various intrinsic factors and bonuses.", 0);
    glut_drawText(2, 34, "Choose a Race (a-c)", 0);
    glut_drawText(2, 35, "a) Human b) Skeleton c) Wraith", 0);
    tila = TILA_UKONKYSELY2;
}
void luokka(void) {
    glut_drawText(2, 28, "Please answer the following questions. Most of the questions", 0);
    glut_drawText(2, 29, "display a set of standard answers and many will also accept", 0);
    glut_drawText(2, 30, "some special responses, including 'Q' to quit, 'S' to restart", 0);
    glut_drawText(2, 31, "and 'R' for random.", 0);
    glut_drawText(2, 32, "Your 'class' determines various intrinsic abilities and bonuses.", 0);
    glut_drawText(2, 34, "Choose a Class (a-b) ", 0);
    glut_drawText(2, 35, "a) Fighter b) Mage", 0);
    tila = TILA_UKONKYSELY3;
}
void energian_piirto(int x) {
    int merkit, i;

    merkit = 100 * ukko.HP / ukko.maxHP;
    merkit = merkit / 10;

    glut_drawText(1, 19, "____________", 1);
    for (i = 1; i < merkit; i++)
        glut_drawText(i, 20, "#", 0);
    glut_drawText(1, 20, "____________", 1);

}
void aika(void) {
    char buf[64];

    sprintf(buf, "| Time: %d:%d   Date: %d.%d |", ukko.hour, ukko.minute, ukko.day, ukko.month);
    glut_drawText(0, MAP_OFFSET_Y - 4, buf, 0);

    sprintf(buf, "| Year: %d               |", ukko.year);
    glut_drawText(0, MAP_OFFSET_Y - 3, buf, 0);
    sprintf(buf, " --------------------------");
    glut_drawText(0, MAP_OFFSET_Y - 2, buf, 0);
}

char* get_species(void) {
    switch(ukko.laji) {
    case 1:
        return "Human";
        break;
    case 2:
        return "Skeleton";
        break;
    case 3:
        return "Wraith";
        break;
    default:
        return "Unknown";
        break;
    }
}

char* get_class(void) {
    switch(ukko.luokka) {
    case 1:
        return "Fighter";
        break;
    case 2:
        return "Mage";
        break;
    default:
        return "Unknown";
        break;
    }
}
