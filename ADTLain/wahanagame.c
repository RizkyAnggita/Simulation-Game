
#include <stdio.h>
#include "wahanagame.h"

WahanaGame MakeWahanaGame(Kata Type, int Price, int Capacity, int DurationW, Kata Description, int MoneyCost, TabBahan BahanCost)
// Membuat wahana game baru dengan atribut sesuai dengan parameter
{
	//KAMUS
	WahanaGame WGame;

	//ALGORITMA
	Type(WGame) = Type;
	Price(WGame) = Price;
	Capacity(WGame) = Capacity;
	DurationW(WGame) = DurationW;
	Description(WGame) = Description;
	MoneyCost(WGame) = MoneyCost;
	BahanCost(WGame) = BahanCost;

	return WGame;
}
