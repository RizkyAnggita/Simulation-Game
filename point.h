/* File: point.h */
/* Tanggal: 28 Agustus 2016 */
/* *** Definisi ABSTRACT DATA TYPE POINT *** */

#ifndef POINT_H
#define POINT_H

#include "boolean.h"

typedef struct
{
   int X; /* absis   */
   int Y; /* ordinat */
} POINT;

/* *** Notasi Akses: Selektor POINT *** */
#define Absis(P) (P).X
#define Ordinat(P) (P).Y

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT(float X, float Y);
/* Membentuk sebuah POINT dari komponen-komponennya */

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ(POINT P1, POINT P2);
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
boolean NEQ(POINT P1, POINT P2);
/* Mengirimkan true jika P1 tidak sama dengan P2 */

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
POINT NextX(POINT P);
/* Mengirim salinan P dengan absis ditambah satu */
POINT NextY(POINT P);
/* Mengirim salinan P dengan ordinat ditambah satu */
POINT PrevX(POINT P);
/* Mengirim salinan P dengan absis dikurng satu */
POINT PrevY(POINT P);
/* Mengirim salinan P dengan ordinat dikurang satu */
POINT PlusDelta(POINT P, int deltaX, int deltaY);
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */

#endif