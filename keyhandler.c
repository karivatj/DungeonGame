#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#include "game.h"
#include "glut_engine.h"

void nappulan_tarkistus(int valinta) {
    switch (tila) {
    case TILA_NORMAALI:
        nappulan_tarkistus_normaalitila(valinta);
        break;
    case TILA_OVENAVAUS:
        nappulan_tarkistus_ovenavaus(valinta);
        break;
    case TILA_OVENSULKEMINEN:
        nappulan_tarkistus_ovensulkeminen(valinta);
        break;
    case TILA_KAIVAMINEN:
        nappulan_tarkistus_kaivaminen(valinta);
        break;
    case TILA_ALOITUS:
        nappulan_tarkistus_aloitus(valinta);
        break;
    case TILA_KUOLEMA:
        nappulan_tarkistus_kuolema(valinta);
        break;
    case TILA_UKONKYSELY1:
        nappulan_tarkistus_ukonkysely(valinta);
        break;
    case TILA_UKONKYSELY2:
        nappulan_tarkistus_ukonkysely_1(valinta);
        break;
    case TILA_UKONKYSELY3:
        nappulan_tarkistus_ukonkysely_2(valinta);
        break;
    case TILA_PULLOKAUPPA:
        nappulan_tarkistus_pullokauppa(valinta);
        break;
    case TILA_KASINO:
        nappulan_tarkistus_kasino(valinta);
        break;
    case TILA_INVENTAARIO:
        nappulan_tarkistus_inv(valinta);
        break;
    case TILA_ITSEMURHA:
        nappulan_tarkistus_itsemurha(valinta);
        break;
    case TILA_ITSEMURHA_TARKISTUS:
        nappulan_tarkistus_itsemurha_tarkistus(valinta);
        break;
    case TILA_JUONTI:
        nappulan_tarkistus_juonti(valinta);
        break;
    default:
        break;
    }
}

void nappulan_tarkistus_ovensulkeminen(int valinta) {
    switch (valinta) {
    case '1':
        oven_sulkeminen_tarkistus(ukko.x - 1, ukko.y + 1);
        break;
    case '2':
        oven_sulkeminen_tarkistus(ukko.x, ukko.y + 1);
        break;
    case '3':
        oven_sulkeminen_tarkistus(ukko.x + 1, ukko.y + 1);
        break;
    case '4':
        oven_sulkeminen_tarkistus(ukko.x - 1, ukko.y);
        break;
    case '5':
        oven_sulkeminen_tarkistus(ukko.x, ukko.y);
        break;
    case '6':
        oven_sulkeminen_tarkistus(ukko.x + 1, ukko.y);
        break;
    case '7':
        oven_sulkeminen_tarkistus(ukko.x - 1, ukko.y - 1);
        break;
    case '8':
        oven_sulkeminen_tarkistus(ukko.x, ukko.y - 1);
        break;
    case '9':
        oven_sulkeminen_tarkistus(ukko.x + 1, ukko.y - 1);
        break;
    default:
        glut_drawText(0, 0, "Cancelled!", 0);
        break;
    }
    tila = TILA_NORMAALI;
}

void nappulan_tarkistus_ovenavaus(int valinta) {
    switch (valinta) {
    case '1':
        oven_avaus_tarkistus(ukko.x - 1, ukko.y + 1);
        break;
    case '2':
        oven_avaus_tarkistus(ukko.x, ukko.y + 1);
        break;
    case '3':
        oven_avaus_tarkistus(ukko.x + 1, ukko.y + 1);
        break;
    case '4':
        oven_avaus_tarkistus(ukko.x - 1, ukko.y);
        break;
    case '5':
        oven_avaus_tarkistus(ukko.x, ukko.y);
        break;
    case '6':
        oven_avaus_tarkistus(ukko.x + 1, ukko.y);
        break;
    case '7':
        oven_avaus_tarkistus(ukko.x - 1, ukko.y - 1);
        break;
    case '8':
        oven_avaus_tarkistus(ukko.x, ukko.y - 1);
        break;
    case '9':
        oven_avaus_tarkistus(ukko.x + 1, ukko.y - 1);
        break;
    default:
        glut_drawText(0, 0, "Cancelled!", 0);
        break;
    }
    tila = TILA_NORMAALI;
}

void nappulan_tarkistus_normaalitila(int valinta) {
    switch (valinta) {
    case '1':
        liikuta(ukko.x - 1, ukko.y + 1);
        tarkista_siirto();
        ukko.moves += 1;
        break;
    case '2':
        liikuta(ukko.x, ukko.y + 1);
        tarkista_siirto();
        ukko.moves += 1;
        break;
    case '3':
        liikuta(ukko.x + 1, ukko.y + 1);
        tarkista_siirto();
        ukko.moves += 1;
        break;
    case '4':
        liikuta(ukko.x - 1, ukko.y);
        tarkista_siirto();
        ukko.moves += 1;
        break;
    case '5':
        liikuta(ukko.x, ukko.y);
        tarkista_siirto();
        ukko.moves += 1;
        break;
    case '6':
        liikuta(ukko.x + 1, ukko.y);
        tarkista_siirto();
        ukko.moves += 1;
        break;
    case '7':
        liikuta(ukko.x - 1, ukko.y - 1);
        tarkista_siirto();
        ukko.moves += 1;
        break;
    case '8':
        liikuta(ukko.x, ukko.y - 1);
        tarkista_siirto();
        ukko.moves += 1;
        break;
    case '9':
        liikuta(ukko.x + 1, ukko.y - 1);
        tarkista_siirto();
        ukko.moves += 1;
        break;
    case 't':
        kaivaminen();
        ukko.moves += 1;
        tarkista_siirto();
        break;
    case 'o':
        oven_avaus();
        ukko.moves += 1;
        tarkista_siirto();
        break;
    case 'c':
        oven_sulkeminen();
        ukko.moves += 1;
        tarkista_siirto();
        break;
    case 'q':
        juonti();
        ukko.moves += 1;
        tarkista_siirto();
        break;
    case 'i':
        inventoori();
        ukko.moves += 1;
        tarkista_siirto();
        break;
    case 'd':
        pudota_tavara(ukko.x, ukko.y);
        ukko.moves += 1;
        tarkista_siirto();
        break;
    case 'Q':
        itse_murha();
        ukko.moves += 1;
        tarkista_siirto();
        break;
    case '=':
        help();
        break;
    case 'b':
        aika();
        break;
    default:
        glut_drawText(0, 0, "Unknown command", 0);
        break;
    }
}
void nappulan_tarkistus_kaivaminen(int valinta) {
    switch (valinta) {
    case '1':
        kaivamis_tarkistus(ukko.x - 1, ukko.y + 1);
        break;
    case '2':
        kaivamis_tarkistus(ukko.x, ukko.y + 1);
        break;
    case '3':
        kaivamis_tarkistus(ukko.x + 1, ukko.y + 1);
        break;
    case '4':
        kaivamis_tarkistus(ukko.x - 1, ukko.y);
        break;
    case 5:
        kaivamis_tarkistus(ukko.x, ukko.y);
        break;
    case '6':
        kaivamis_tarkistus(ukko.x + 1, ukko.y);
        break;
    case '7':
        kaivamis_tarkistus(ukko.x - 1, ukko.y - 1);
        break;
    case '8':
        kaivamis_tarkistus(ukko.x, ukko.y - 1);
        break;
    case '9':
        kaivamis_tarkistus(ukko.x + 1, ukko.y - 1);
        break;
    default:
        glut_drawText(0, 0, "Cancelled!", 0);
        break;
    }
    tila = TILA_NORMAALI;
}
void nappulan_tarkistus_inv(int valinta) {
    switch (valinta) {
    case 27:
        tila = TILA_NORMAALI;
        break;
    }
}
void nappulan_tarkistus_kasino(int valinta) {

}

void nappulan_tarkistus_aloitus(int valinta) {

}

void nappulan_tarkistus_kuolema(int valinta) {
    glut_quit();
}
void nappulan_tarkistus_ukonkysely(int valinta) {
    int arpominen;
    switch (valinta) {
    case 'a':
        ukko.sukupuoli = 1;
        tila = TILA_UKONKYSELY2;
        break;
    case 'b':
        ukko.sukupuoli = 2;
        tila = TILA_UKONKYSELY2;
        break;
    case 'R':
        arpominen = rand() % 1;
        if (arpominen == 0) {
            ukko.sukupuoli = 1;
        }
        if (arpominen == 1) {
            ukko.sukupuoli = 2;
        }
        tila = TILA_UKONKYSELY2;
        break;
    case 'S':
        tila = TILA_UKONKYSELY1;
        break;
    case 'Q':
        glut_quit();
        break;
    default:
        break;
    }
}
void nappulan_tarkistus_ukonkysely_1(int valinta) {
    int arpominen;
    switch (valinta) {
    case 'a':
        ukko.laji = 1;
        tila = TILA_UKONKYSELY3;
        break;
    case 'b':
        ukko.laji = 2;
        tila = TILA_UKONKYSELY3;
        break;
    case 'c':
        ukko.laji = 3;
        tila = TILA_UKONKYSELY3;
        break;
    case 'R':
        arpominen = rand() % 2;

        if (arpominen == 0) {
            ukko.laji = 1;
        }
        if (arpominen == 1) {
            ukko.laji = 2;
        }
        if (arpominen == 2) {
            ukko.laji = 3;
        }
        tila = TILA_UKONKYSELY3;
        break;
    case 'S':
        tila = TILA_UKONKYSELY1;
        break;
    case 'Q':
        glut_quit();
        break;
    default:
        break;
    }
}
void nappulan_tarkistus_ukonkysely_2(int valinta) {
    int arpominen;

    switch (valinta) {
    case 'a':
        ukko.luokka = 1;
        tila = TILA_NORMAALI;
        break;
    case 'b':
        ukko.luokka = 2;
        tila = TILA_NORMAALI;
        break;
    case 'R':
        arpominen = rand() % 1;
        if (arpominen == 0) {
            ukko.luokka = 1;
        }
        if (arpominen == 1) {
            ukko.luokka = 2;
        }
        tila = TILA_NORMAALI;
        break;
    case 'S':
        tila = TILA_UKONKYSELY1;
        break;
    case 'Q':
        glut_quit();
        break;
    default:
        break;
    }
}
void nappulan_tarkistus_pullokauppa(int valinta) {
    switch (valinta) {
    case 'a':
        if (ukko.kaupan_pullo <= 0) {
            glut_drawText(0, 0, "There is no more Potion(s) of Healing", 0);
            ukko.kaupan_pullo = 0;
            ukko.pullo += 0;
        }
        if (ukko.raha < ukko.hinta) {
            glut_drawText(0, 1, "Hey,you don't have the gold for that.", 0);
            ukko.raha -= 0;
            ukko.kaupan_pullo -= 0;
            ukko.pullo += 0;
        }
        if (ukko.raha > ukko.hinta) {

            ukko.raha -= ukko.hinta;
            ukko.pullo += 1;
            ukko.kaupan_pullo -= 1;
        } else {
            tila = TILA_PULLOKAUPPA;
        }
        break;
    case 27:
        tila = TILA_NORMAALI;
        break;
    default:
        break;
    }
}

void nappulan_tarkistus_itsemurha(int valinta) {
    switch (valinta) {
    case 'y':
        itse_murha_tarkistus();
        break;
    case 'n':
        tila = TILA_NORMAALI;
        break;
    default:
        break;
    }
}

void nappulan_tarkistus_itsemurha_tarkistus(int valinta) {
    switch (valinta) {
    case '@':
        glut_clearGraphics();
        kuolema();
        break;
    default:
        glut_drawText(0, 0, "You stopped yourself at the last minute!", 0);
        tila = TILA_NORMAALI;
        break;
    }
}

void nappulan_tarkistus_juonti(int valinta) {
    switch (valinta) {
    case 'a':
        if (ukko.pullo > 0) {
            ukko.HP = ukko.maxHP;
            ukko.pullo -= 1;
        } else {
            glut_drawText(0, 0, "No potions of that kind!", 0);
        }
        break;
    case 27:
        tila = TILA_NORMAALI;
        break;
    default:
        break;
    }
}
