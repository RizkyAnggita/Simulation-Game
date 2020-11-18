
#include <stdio.h>

#include "boolean.h"
#include "mesinkata.h"
#include "jam.h"

#define ENDL printf("\n")


boolean IsKataSama(Kata K1, Kata K2)
/*Mengembalikan True jika kita sama, false jika tidak*/
{
	//KAMUS
	int i;
	//ALGORITMA
	if (K1.Length == K2.Length)
	{
		for (i = 0; i < K1.Length; ++i)
		{
			if (K1.TabKata[i] != K2.TabKata[i])
			{
				return false;
			}
		}
		return true;
	} else 
	{
		return false;
	}
}

void CopyKata(Kata K1, Kata *K2)
/* Menyalin kata K1 ke kata K2
   I.S.  : K2 terdefinisi kosong
   F.S.  : K2 memiliki TabKata dan Length yang sama dengan K1*/
{
	//KAMUS
	int i;

	//ALGORITMA
	(*K2).Length = K1.Length;
	for (i = 0; i < K1.Length; ++i)
	{
		(*K2).TabKata[i] = K1.TabKata[i];
	}
}

void PrintKata(Kata K)
/* Menampilkan kata K ke layar*/
{
	//KAMUS
	int i;

	//ALGORITMA
	for (i = 0; i < K.Length; ++i)
		printf("%c", K.TabKata[i]);
}

void PrintTitle()
/*Menampilkan ke layar pembukaan dari game*/
{
	printf("// Welcome to Willy wangky's fum factory!!//");
}

void PrintMainMenu()
/*Menampilkan main menu ke layar*/
{
	printf("// New game / load game / exit? //");
}

void PrintMap()
/*Menampilkan map beserta legend ke layar*/
{
	//Menampilkan map 
	printf("//INSERT MAP HERE\n");

	//Menampilkan legend
	printf("Legend:\n");
	printf("A = Antrian\n");
	printf("P = Player\n");
	printf("W = Wahana\n");
	printf("O = Office\n");
	printf("<, ^, >, v = Gerbang");
}

void PrintPlayerStat(Kata username)
/* Menampilkan stat utama pemain seperti nama, money, dan time */
{
	printf("Name: ");
	PrintKata(username);
	ENDL;

	printf("Money: 1000");
}

void PrintTime(JAM CurrentTime, JAM EndTime, boolean PrepPhase)
/* Menampilkan waktu untuk preparation phase */
{
	//KAMUS
	JAM TR;

	//ALGORITMA
	printf("Current Time: ");
	TulisJAM(CurrentTime);
	ENDL;

	if (PrepPhase)
	{
		printf("Opening Time: ");
	} else
	{
		printf("Closing Time: ");
	}
	TulisJAM(EndTime);
	ENDL;

	TR = DetikToJAM(Durasi(CurrentTime, EndTime));
	printf("Time Remaining: %d hour(s) %d minute(s) %d second(s)", Hour(TR), Minute(TR), Second(TR));
}

void PrintPrepStat()
/* Menampilkan stat khusus preparation day, total aksi waktu
   dan uang yang dibutuhkan */
{
	printf("Total aksi yang akan dilakukan: 1\n");
	printf("Total waktu yang dibutuhkan: 1 hour(s) 45 minute(s)\n");
	printf("Total uang yang dibutuhkan: 60");
}

void PrintMainQueue()
/* Menampilkan  antrian pengunjung saat main phase*/
{
	printf("Antrian [1/5]:\n");
	printf("(Wangky's Universe), Kesabaran: 5");
}
