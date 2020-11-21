
#ifndef instruction_h
#define instruction_h

#include "point.h"

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
	int Map;
} Instruction;

// !!!======!!! Selektor !!!======!!!
#define Function(I) (I).Function
#define Point(I) (I).Point
#define Detail(I) (I).Detail
#define Map(I) (I).Map

Instruction CreateInstruction(Kata command, POINT point, Kata detail, int map);
/* Membuat instruction baru dengan komponen seperti pada parameter dan mengembalikannya*/

#endif

