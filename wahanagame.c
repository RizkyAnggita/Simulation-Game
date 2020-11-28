
#include <stdio.h>
#include "wahanagame.h"

WahanaGame MakeWahanaGame(Kata Type, int Price)
// Membuat wahana game baru dengan atribut sesuai dengan parameter
{
	//KAMUS
	WahanaGame WGame;

	//ALGORITMA
	Type(WGame) = Type;
	Price(WGame) = Price;

	return WGame;
}
