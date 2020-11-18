// Nama/NIM : Muhammad Atthaumar Rifqy/13519148
// Nama file: instruction.c
// Topik	: Tugas Besar
// Tanggal  : 9 November 2020
// Deskripsi: Header Instruction

#ifndef instruction_h
#define instruction_h

#include "point.h"
#include "mesinkata.h"

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
} Instruction;

// !!!======!!! Selektor !!!======!!!
#define Function(I) (I).Function
#define Point(I) (I).Point
#define Detail(I) (I).Detail

// !!==!! Definisi KATA Fungsi !!==!!
#define Build {.TabKata = {'b', 'u', 'i', 'l', 'd'}, .Length = 5}
#define Upgrade {.TabKata = {'u', 'p', 'g', 'r', 'a', 'd', 'e'}, .Length = 7}
#define Buy {.TabKata = {'b', 'u', 'y'}, .Length = 3}

#endif

