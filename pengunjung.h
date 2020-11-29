
#ifndef __PENGUNJUNG_H__
#define __PENGUNJUNG_H__

typedef struct 
{
	int Prio;
	Kata[] ListWPeng;
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


