
#ifndef PULLA_H
#define PULLA_H
#define UKKO_ALAS  ukko.y += 1
#define UKKO_YLOS  ukko.y -= 1
#define UKKO_OIK   ukko.x += 1
#define UKKO_VAS   ukko.x -= 1
#define UKKO_HP(x) ukko.HP += x
#define AIKA_SIIRROS 8
#define AIKA_SIIRROS_2 50
#define RUOAN_SULATUS 7
#define RUOAN_SULATUS_2 25
#define KARTTA1_X     37
#define KARTTA1_Y     25
#define PAIKKA(mx1,my1) (KARTTA1_X*(my1)+(mx1))
#define MAP_OFFSET_X 11
#define MAP_OFFSET_Y 4
char* get_species(void);
char* get_class(void);
void kartan_piirto(void);
void lamppu (int lamppu);
void nappulan_tarkistus(int valinta);
void kuolema(void);
void kaivaminen(void);
void oven_avaus(void);
void oven_avaus_tarkistus(int cx, int cy);
void tarkista_siirto(void);
void liikuta(int cx, int cy);
void kaivamis_tarkistus(int cx, int cy);
void oven_sulkeminen(void);
void oven_sulkeminen_tarkistus(int cx, int cy);
void juonti(void);
void pudota_tavara(int cx, int cy);
void inventoori(void);
void sponsori (void);
void casino(void);
void itse_murha(void);
void kolikko_peli(void);
void pullo_kauppa(void);
void luokka (void);
void laji (void);
void sukupuoli(void);
void numero_paneeli(void);
void numero_paneeli_2(void);
void sponsori_3 (void);
void sponsori_2(void);
void ruletti(void);
void itse_murha_tarkistus(void);
void aija(void);
void help(void);
void ruletti_loppu(void);
void ruletti_kysma(void);
void energian_piirto(int hp);
void food_status(int food);
void nappulan_tarkistus_ovensulkeminen(int valinta);
void nappulan_tarkistus_ovenavaus(int valinta);
void nappulan_tarkistus_normaalitila(int valinta);
void nappulan_tarkistus_kaivaminen(int valinta);
void nappulan_tarkistus_kasino(int valinta);
void nappulan_tarkistus_aloitus(int valinta);
void nappulan_tarkistus_kuolema(int valinta);
void nappulan_tarkistus_ukonkysely(int valinta);
void nappulan_tarkistus_ukonkysely_1(int valinta);
void nappulan_tarkistus_ukonkysely_2(int valinta);
void nappulan_tarkistus_pullokauppa(int valinta);
void nappulan_tarkistus_inv(int valinta);
void nappulan_tarkistus_itsemurha(int valinta);
void nappulan_tarkistus_itsemurha_tarkistus(int valinta);
void nappulan_tarkistus_juonti(int valinta);
void redraw_Screen(void);
void aika (void);

typedef struct {
	char kartta[KARTTA1_X*KARTTA1_Y];
	char hidden[KARTTA1_X*KARTTA1_Y];
} KARTTA;

typedef struct {
	char nimi[40];
	int paino;
	int suojaus;
	int vaurio;
	int status;
	int nopeus;
	int tohit;
	int todam;
	int kuva;
	int STR;
	int INT;
	int WIS;
	int DEX;
	int CON;
	int CHR;
} TAVARA,ARTIFACT;

typedef struct {
	char nimi[40];
	int tayttavyys;
	int myrkytys;
	int parannus;
	int STR;
	int INT;
	int WIS;
	int DEX;
	int CON;
	int CHR;
}RUOKA;

typedef struct {
	int used;
	int index;
	int amount;
} INV_ITEM;

typedef struct {
	int x;
	int y;
	int HP;
	int maxHP;
//  int panos;
	int ravinto;
	int purple_avain;
	int voima;
	int lamppu;
	int ketteryys;
	int curse;
	int second;
	int minute;
	int hour;
	int day;
	int hinta;
	int month;
	int year;
	int kartta;
	int moves;
	KARTTA *map;
	int sininen_avain;
	int punainen_avain;
	int pullo;
	int keltainen_avain;
	int map_number;
	int expo;
	int raha;
	int level;
	int alykkyys;
	int viisaus;
	int kestavyys;
	int charisma;
	int raha_maara;
	int AC;
	int mana;
	char nimi [20];
	int maxmana;
	int kaupan_pullo;
	int sukupuoli;
	int laji;
	int luokka;
	char kuolin_syy[100];
	INV_ITEM inventaario[23];
} UKKO;

//RES = resist
//IM  = immunity
//bin = Binääri järjestelmä
#define STATUS_BRAND_TULI			0x00000000001  /* bin 00000000000000000000000000000001 */
#define STATUS_BRAND_JAA		    0x00000000002  /* bin 00000000000000000000000000000010 */
#define STATUS_BRAND_HAPPO	  		0x00000000004  /* bin 00000000000000000000000000000100 */
#define STATUS_BRAND_KIROTTU		0x00000000008  /* bin 00000000000000000000000000001000 */
#define STATUS_BRAND_SHARP	 		0x00000000010  /* bin 00000000000000000000000000010000 */
#define STATUS_BRAND_SAHKO 			0x00000000020  /* bin 00000000000000000000000000100000 */
#define STATUS_BRAND_MYRKKY			0x00000000040  /* bin 00000000000000000000000001000000 */
#define STATUS_RES_TULI				0x00000000080  /* bin 00000000000000000000000010000000 */
#define STATUS_RES_JAA			 	0x00000000100  /* bin 00000000000000000000000100000000 */
#define STATUS_RES_HAPPO			0x00000000200  /* bin 00000000000000000000001000000000 */
#define STATUS_RES_SAHKO			0x00000000400  /* bin 00000000000000000000010000000000 */
#define STATUS_RES_MYRKKY			0x00000000800  /* bin 00000000000000000000100000000000 */
#define STATUS_RES_PIMEYS		 	0x00000020000  /* bin 00000000000000100000000000000000 */
#define STATUS_RES_VALO			 	0x00000040000  /* bin 00000000000001000000000000000000 */
#define STATUS_RES_NETHER		 	0x00000080000  /* bin 00000000000010000000000000000000 */
#define STATUS_RES_NEXUS		 	0x00000100000  /* bin 00000000000100000000000000000000 */
#define STATUS_RES_CHAOS		 	0x00000200000  /* bin 00000000001000000000000000000000 */
#define STATUS_RES_SHARDS		 	0x00000400000  /* bin 00000000010000000000000000000000 */
#define STATUS_RES_SOUND		 	0x00000800000  /* bin 00000000100000000000000000000000 */
#define STATUS_RES_DISEN			0x00001000000  /* bin 00000001000000000000000000000000 */
#define STATUS_RES_BLIND			0x00002000000  /* bin 00000010000000000000000000000000 */
#define STATUS_RES_CONF			 	0x00004000000  /* bin 00000100000000000000000000000000 */
#define STATUS_IM_TULI				0x00000001000  /* bin 00000000000000000001000000000000 */
#define STATUS_IM_JAA				0x00000002000  /* bin 00000000000000000010000000000000 */
#define STATUS_IM_HAPPO		 	 	0x00000004000  /* bin 00000000000000000100000000000000 */
#define STATUS_IM_SAHKO		 	 	0x00000008000  /* bin 00000000000000001000000000000000 */
#define STATUS_IM_MYRKKY		 	0x00000010000  /* bin 00000000000000010000000000000000 */
#define STATUS_IM_PIMEYS			0x00008000000  /* bin 00001000000000000000000000000000 */
#define STATUS_IM_VALO				0x00010000000  /* bin 00010000000000000000000000000000 */
#define STATUS_IM_NETHER			0x00020000000  /* bin 00100000000000000000000000000000 */
#define STATUS_IM_NEXUS			 	0x00040000000  /* bin 01000000000000000000000000000000 */
#define STATUS_IM_CHAOS			 	0x00080000000  /* bin 10000000000000000000000000000000 */
#define STATUS_IM_SHARDS	 		0x00100000000  /* bin 10000000000000000000000000000001 */
#define STATUS_IM_SOUND			 	0x00200000000  /* bin 10000000000000000000000000000010 */
#define STATUS_IM_DISEN				0x00400000000  /* bin 10000000000000000000000000000011 */
#define STATUS_IM_BLIND				0x00800000000  /* bin 10000000000000000000000000000100 */
#define STATUS_IM_CONF				0x01000000000  /* bin 10000000000000000000000000000101 */

#if  0
typedef struct {
	char nimi[40];
	int  HP;
	int  nopeus;
	int  stats;
} hirviö;
#endif

typedef enum {
	TILA_NORMAALI,
	TILA_OVENAVAUS,
	TILA_OVENSULKEMINEN,
	TILA_KAIVAMINEN,
	TILA_KASINO,
	TILA_ALOITUS,
	TILA_KUOLEMA,
	TILA_UKONKYSELY1,
	TILA_UKONKYSELY2,
	TILA_UKONKYSELY3,
	TILA_PULLOKAUPPA,
	TILA_INVENTAARIO,
	TILA_ITSEMURHA,
	TILA_ITSEMURHA_TARKISTUS,
	TILA_JUONTI
} TILA;

extern UKKO ukko;
extern TILA tila;
extern TAVARA tavara_taulu[];
extern ARTIFACT tavara_taulu_2[];
extern RUOKA tavara_taulu_3[];

extern KARTTA kartta;
extern KARTTA kartta_2;
extern KARTTA kartta_3;
extern KARTTA kartta_4;
extern KARTTA kartta_5;
extern KARTTA kartta_6;
extern KARTTA kartta_7;
extern KARTTA kartta_8;
extern KARTTA kartta_9;
extern KARTTA kartta_10;
extern KARTTA kartta_11;
extern KARTTA kartta_12;
extern KARTTA kartta_13;

#endif /* PULLA_H */
