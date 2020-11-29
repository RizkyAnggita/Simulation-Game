
#ifndef instruction_h
#define instruction_h

#include "point.h"
#include "mesinkata.h"
#include "arraybahan.h"

// Definisi Instruction
/*
Instruction memiliki tiga data, yaitu:
- Function : Fungsi yang akan dijalankan
			 Ada tiga macam fungsi : Build, Upgrade, Buy
			 Function berbentuk KATA
- POINT    : Titik di map yang merupakan lokasi dilakukan
			 fungsi
			 Point berbentuk POINT
- Detail   : Detail fungsi yang dijalankan
			 Untuk Build : Nama wahana
			 Untuk Upgrade: Macam upgrade
			 Untuk Buy : Macam bahan yang dibeli (?)
			 Detail berbentuk KATA
*/
typedef struct {
	Kata Function;
	POINT Point;
	Kata Detail;
	int Qty;
	int Map;
	int MCost;
	TabBahan BCost;
} Instruction;

// !!!======!!! Selektor !!!======!!!
#define Function(I) (I).Function
#define Point(I) (I).Point
#define Detail(I) (I).Detail
#define Quantity(I) (I).Qty
#define Map(I) (I).Map
#define MCost(I) (I).MCost
#define BCost(I) (I).BCost


Instruction CreateInstruction(Kata command, POINT point, Kata detail, int qty, int map, int mcost, TabBahan bcost);
/* Membuat instruction baru dengan komponen seperti pada parameter dan mengembalikannya*/

#endif

