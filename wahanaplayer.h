/* Tipe bentukan wahana player*/

#ifndef __WAHANAPLAYER_H__
#define __WAHANAPLAYER_H__

/* Modul lain yang digunakan */
#include "wahanagame.h"
#include "mesinkata.h"
#include "point.h"
#include "boolean.h"



typedef struct {
	WahanaGame StatW;
	Kata NamaW;
	POINT LocW;
	int MapW;
	//HIstory upgrade
	int TotalPlayW;
	int TotalPlayDayW;
	int TotalMoneyW;
	int TotalMoneyDayW;
	boolean BrokenW;
} WahanaPlayer;


#endif