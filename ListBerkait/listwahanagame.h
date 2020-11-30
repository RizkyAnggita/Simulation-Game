/* ADT LIST WAHANA GAME  IMPLEMENTASI LIST LINIER */

#ifndef __LISTWAHANAGAME_H__
#define __LISTWAHANAGAME_H__

#include "../ADTLain/boolean.h"
#include "../BinTree/bintree.h"
#include "../ADTLain/wahanagame.h"

#define NilListWG NULL

typedef BinTree infotypeListWG;
typedef struct tElmtListWG * addressListWG;
typedef struct tElmtListWG {
	infotypeListWG info;
	addressListWG next;
} ElmtListWG;

typedef struct {
	addressListWG First;
} ListWG;

#define InfoListWG(P) (P)->info
#define NextListWG(P) (P)->next
#define FirstListWG(L) ((L).First) 

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyListWG (ListWG L);
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyListWG (ListWG *L);
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** Manajemen Memori ******************/
addressListWG AlokasiListWG (infotypeListWG X);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */


/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirstListWG (ListWG *L, infotypeListWG X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */

#endif