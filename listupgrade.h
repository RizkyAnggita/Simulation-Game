/* ADT history list upgrade wahana dengan implementasi list linier berkait */

#ifndef __LISTUPGRADE_H__
#define __LISTUPGRADE_H__

#define NilListU NULL


#include "mesinkata.h"


typedef Kata infotypeListU;
typedef struct tElmtListU * addressListU;
typedef struct tElmtListU {
	infotypeListU info;
	addressListU next;
} ElmtListU;
typedef struct {
	addressListU First;
} ListU;

/* Selektor */

#define InfoListU(P) (P)->info
#define NextListU(P) (P)->next
#define FirstListU(L) ((L).First)

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyListU (ListU L);
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyListU (ListU *L);
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** Manajemen Memori ******************/
address AlokasiListU (infotypeListU X);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirstListU (ListU *L, infotypeListU X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */

#endif