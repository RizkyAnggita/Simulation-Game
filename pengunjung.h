
#ifndef __PENGUNJUNG_H__
#define __PENGUNJUNG_H__
#include "mesinkata.h"
#include "arraywahanaplayer.h"

#include "mesinkata.h"

typedef struct 
{
	int Prio;
	Kata *ListWPeng;
	int TotalWPeng;
	int CurrWPeng;
	int Kesabaran;
} Pengunjung;

/* Selektor */
#define Prio(P) (P).Prio
#define ElmtWPengunjung(P, i) (P).ListWPeng[(i)]
#define TotalWPeng(P) (P).TotalWPeng
#define CurrWPeng(P) (P).CurrWPeng
#define Kesabaran(P) (P).Kesabaran

Pengunjung GeneratePengunjung (TabWahanaPlayer T);
/* Mengenerate seorang pengunjung dengan melakukan randomisasi
jumlah wahana dan wahana apa saja yang dinaiki pengunjung tersebut */

void PrintPengunjung(Pengunjung P);
    /* Mencetak Wahana apa saja yang ingin dinaiki pengunjung dan tingkat kesabarannya */
#endif

