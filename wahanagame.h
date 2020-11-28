/* ADT Wahana Data Game */

#ifndef __WAHANAGAME_H__
#define __WAHANAGAME_H__

/* Modul lain yang digunakan */
#include "mesinkata.h"
#include "arraybahan.h"


/* Definisi Type Wahana Game */
typedef struct {
	Kata Type;
	int Price;
	int Capacity;
	int DurationW;
	Kata Description;
	int MoneyCost;
	TabBahan BahanCost;
} WahanaGame;


/* Selektor */
#define Type(WG) WG.Type
#define Price(WG) WG.Price
#define Capacity(WG) WG.Capacity
#define DurationW(WG) WG.DurationW
#define Description(WG) WG.Description
#define MoneyCost(WG) WG.MoneyCost
#define BahanCost(WG) WG.BahanCost


WahanaGame MakeWahanaGame(Kata Type, int Price, int Capacity, int DurationW, Kata Description, int MoneyCost, TabBahan BahanCost);
// Membuat wahana game baru dengan atribut sesuai dengan parameter

#endif