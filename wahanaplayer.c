
#include "wahanaplayer.h"
#include <stdio.h>

/* Pembuatan WahanaPlayer */

WahanaPlayer MakeWahanaPlayer(WahanaGame StatW, Kata NamaW, POINT LocW, int MapW, ListU HUpgradeW, int TotalPlayW, int TotalPlayDayW, int TotalMoneyW, int TotalMoneyDayW, boolean BrokenW)
//Membuat Wahana player dengan atribut yang ada pada parameter
{
	WahanaPlayer W;

	StatW(W) = StatW;
	NamaW(W) = NamaW;
	LocW(W) = LocW;
	MapW(W) = MapW;
	HUpgradeW(W) = HUpgradeW;
	TotalPlayW(W) = TotalPlayW;
	TotalPlayDayW(W) = TotalPlayDayW;
	TotalMoneyW(W) = TotalMoneyW;
	TotalMoneyDayW(W) = TotalMoneyDayW;
	BrokenW(W) = BrokenW;

	return W;
}

WahanaPlayer MakeWahanaPlayerUndef()
//Membuat wahana player yang undefined, digunakkan utk array wahanaplayer
{
	WahanaPlayer W;

	TotalPlayW(W) = -999;

	return W;
}