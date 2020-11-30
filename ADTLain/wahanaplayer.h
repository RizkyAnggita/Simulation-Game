/* Tipe bentukan wahana player*/

#ifndef __WAHANAPLAYER_H__
#define __WAHANAPLAYER_H__

/* Modul lain yang digunakan */
#include "../BinTree/bintree.h"
#include "../MesinKata/mesinkata.h"
#include "../Point/point.h"
#include "boolean.h"
#include "../ListBerkait/listupgrade.h"



typedef struct {
	BinTree StatW;
	Kata NamaW;
	POINT LocW;
	int MapW;
	ListU HUpgradeW;
	int TotalPlayW;
	int TotalPlayDayW;
	int TotalMoneyW;
	int TotalMoneyDayW;
	boolean BrokenW;
} WahanaPlayer;

/* Selektor */

#define StatW(W) (W).StatW
#define NamaW(W) (W).NamaW
#define LocW(W) (W).LocW
#define MapW(W) (W).MapW
#define HUpgradeW(W) (W).HUpgradeW
#define TotalPlayW(W) (W).TotalPlayW
#define TotalPlayDayW(W) (W).TotalPlayDayW
#define TotalMoneyW(W) (W).TotalMoneyW
#define TotalMoneyDayW(W) (W).TotalMoneyDayW
#define BrokenW(W) (W).BrokenW

/* Pembuatan WahanaPlayer */

WahanaPlayer MakeWahanaPlayer(BinTree StatW, Kata NamaW, POINT LocW, int MapW, ListU HUpgradeW, int TotalPlayW, int TotalPlayDayW, int TotalMoneyW, int TotalMoneyDayW, boolean BrokenW);
//Membuat Wahana player dengan atribut yang ada pada parameter

WahanaPlayer MakeWahanaPlayerUndef();
//Membuat wahana player yang undefined, yaitu TotalPlayW = -999, digunakkan utk array wahanaplayer



#endif