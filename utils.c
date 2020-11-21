
#include <stdio.h>

#include "utils.h"

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


TabBahan FileToListBahan()
/* Membaca file yang berisi nama bahan beserta harganya */
/* Mengembalikan list bahan  */
{
	//KAMUS
	TabBahan ListBahan;
	int i;

	//ALGORITMA
	MakeEmptyListBahan(&ListBahan);

	STARTBAHAN("materials.txt");

	i = 0;
	while (!EndBahan)
	{
		// printf("%d ", CBahan.Val);
		// PrintKata(CBahan.Name);
		// ENDL;
		Elmt(ListBahan, i) = CBahan;
		i += 1;

		ADVBAHAN();
	}

	return ListBahan;
}

TabBahan CreateEmptyBahanPlayer(TabBahan ListBahan)
/* Membuat inventory utk penyimpanan bahan player
   Semua val pada elemen list diset ke 0 */
{
	//KAMUS
	IdxType i;

	//ALGORITMA
	for (i = GetFirstIdxListBahan(ListBahan); i <= GetLastIdxListBahan(ListBahan); ++i)
	{
		Val(Elmt(ListBahan, i)) = 0;
	}

	return ListBahan;
}

void PrintBahanPlayer(TabBahan ListBahan)
/* I.S. ListBahan terdefinisi 
   F.S Isi dari ListBahan ditampilkan ke layar dengan format "{name}: {qty}"*/
{
	//KAMUS
	IdxType i;

	//ALGORITMA

	printf("Inventory Bahan\n");
	printf("List: (Nama): (qty)\n");

	for (i = GetFirstIdxListBahan(ListBahan); i <= GetLastIdxListBahan(ListBahan); ++i)
	{
		printf("    - ");
		PrintKata(Name(Elmt(ListBahan, i)));
		printf(": %d\n", Val(Elmt(ListBahan, i)));
	}
}

void PrintBuyBahan(TabBahan ListBahan)
/* I.S. ListBahan terdefinisi 
   F.S Isi dari ListBahan ditampilkan ke layar dengan format "{name}: {value}"*/
{
	//KAMUS
	IdxType i;

	//ALGORITMA

	printf("Ingin membeli apa?\n");
	printf("List: (Nama): (Harga)\n");

	for (i = GetFirstIdxListBahan(ListBahan); i <= GetLastIdxListBahan(ListBahan); ++i)
	{
		printf("    - ");
		PrintKata(Name(Elmt(ListBahan, i)));
		printf(": %d\n", Val(Elmt(ListBahan, i)));
	}
}

int PriceBuyBahan(Kata name, int qty, TabBahan ShopBahan)
/* Menghitung harga yang perlu dibayar untuk membeli bahan dengan quantity tertentu 
   Mengembalikan total harga jika bahan yang ingin dibeli pengguna (name) ada di 
   shop bahan
   Jika tidak ada di shop bahan, akan mengembalikan total harga -999*/
{
	//KAMUS
	IdxType i;
	boolean found;
	int price;

	//ALGORITMA

	i = GetFirstIdxListBahan(ShopBahan);
	found = false;

	while ((i <= GetLastIdxListBahan(ShopBahan)) && (!found))
	{
		if (IsKataSama(name, Name(Elmt(ShopBahan, i))))
		{
			price = qty * Val(Elmt(ShopBahan, i));
			found = true;
		}

		i += 1;
	}

	if (!found)
	{
		price = -999;
	}

	return price;
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
	JAM TR; // TR = Time Remaining

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

void PrintPrepStat(JAM TS)
/* TS = Time Spent */
/* Menampilkan stat khusus preparation day, total aksi waktu
   dan uang yang dibutuhkan */
{
	printf("Total aksi yang akan dilakukan: 1\n");

	printf("Total waktu yang dibutuhkan: %d hour(s) %d minute(s) %d second(s)", Hour(TS), Minute(TS), Second(TS));
	ENDL;

	printf("Total uang yang dibutuhkan: 60");
}

void PrintMainQueue()
/* Menampilkan  antrian pengunjung saat main phase*/
{
	printf("Antrian [1/5]:\n");
	printf("(Wangky's Universe), Kesabaran: 5");
}
