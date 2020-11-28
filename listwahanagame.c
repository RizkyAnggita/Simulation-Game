
#include "listwahanagame.h"
#include <stdlib.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyListWG (ListWG L)
/* Mengirim true jika list kosong */
{
	return FirstListWG(L) == NilListWG;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyListWG (ListWG *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
	FirstListWG(*L) = NilListWG;
}

/****************** Manajemen Memori ******************/
addressListWG AlokasiListWG (infotypeListWG X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
	addressListWG P = malloc(sizeof(addressListWG));
	NextListWG(P) = NilListWG;
	InfoListWG(P) = X;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirstListWG (ListWG *L, infotypeListWG X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
	addressListWG P;

	P = AlokasiListWG(X);
	if (P != NilListWG)
	{
		NextListWG(P) = FirstListWG(*L);
		FirstListWG(*L) = P;
	}
}
