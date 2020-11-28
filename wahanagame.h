/* ADT Wahana Data Game */

#ifndef __WAHANAGAME_H__
#define __WAHANAGAME_H__

/* Modul lain yang digunakan */
#include "mesinkata.h"


/* Definisi Type Wahana Game */
typedef struct {
	Kata Type;
	int Price;
	// int Capacity;
	// int Duration;
	// Kata Description;
	// int Cost;

} WahanaGame;


/* Selektor */
#define Type(WG) WG.Type
#define Price(WG) WG.Price


WahanaGame MakeWahanaGame(Kata Type, int Price);
// Membuat wahana game baru dengan atribut sesuai dengan parameter

#endif