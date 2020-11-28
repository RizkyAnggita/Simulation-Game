
#include "listupgrade.h"
#include <stdio.h>
#include <stdlib.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyListU (ListU L)
/* Mengirim true jika list kosong */
{
	return FirstListU(L) == NilListU;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyListU (ListU *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
	FirstListU(*L) = NilListU;
}

/****************** Manajemen Memori ******************/
addressListU AlokasiListU (infotypeListU X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
	addressListU P = (addressListU) malloc(sizeof(addressListU));
	if (P != NilListU)
	{
		NextListU(P) = NilListU;
		InfoListU(P) = X;
	}
	return P;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirstListU (ListU *L, infotypeListU X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
	addressListU P;

	P = AlokasiListU(X);

	if (P != NilListU)
	{
		NextListU(P) = FirstListU(*L);
		FirstListU(*L) = P;
	}
}