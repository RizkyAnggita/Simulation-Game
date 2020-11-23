/* File: point.h */
// Nama : Ariya Adinatha
// NIM : 13519048
/* Tanggal: 2 September 2020 */
/* *** Definisi ABSTRACT DATA TYPE POINT *** */

#include <stdio.h>
#include <math.h>
#include "point.h"


/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT(float X, float Y)
{
   POINT P;
   Absis(P) = X;
   Ordinat(P) = Y;

   return P;
}
/* Membentuk sebuah POINT dari komponen-komponennya */


/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ(POINT P1, POINT P2)
{
   return ((Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2)));
}
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
boolean NEQ(POINT P1, POINT P2)
{
   return (!EQ(P1, P2));
}
/* Mengirimkan true jika P1 tidak sama dengan P2 */

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
POINT NextX(POINT P)
{
   return (MakePOINT(Absis(P) + 1, Ordinat(P)));
}
/* Mengirim salinan P dengan absis ditambah satu */
POINT NextY(POINT P)
{
   return (MakePOINT(Absis(P), Ordinat(P) + 1));
}
/* Mengirim salinan P dengan ordinat ditambah satu */
POINT PrevX(POINT P)
{
   return (MakePOINT(Absis(P) - 1, Ordinat(P)));
}
/* Mengirim salinan P dengan absis dikurng satu */
POINT PrevY(POINT P)
{
   return (MakePOINT(Absis(P), Ordinat(P) - 1));
}
/* Mengirim salinan P dengan ordinat dikurang satu */
POINT PlusDelta(POINT P, int deltaX, int deltaY)
{
   return (MakePOINT(Absis(P) + deltaX, Ordinat(P) + deltaY));
}
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
