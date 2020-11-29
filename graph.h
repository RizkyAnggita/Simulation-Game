/* ADT Graph */

#ifndef _GRAPH_H_
#define _GRAPH_H_

/* Modul lain yang digunakan : */

#include "boolean.h"
#include "matriks.h"

#define NilG NULL

/* Definisi Type */
typedef struct NodeG *adrNodeG;
typedef struct SuccNodeG *adrSuccNodeG;
typedef struct NodeG
{
    int Id;
    int NPred;
    MATRIKS Map;
    adrSuccNodeG Trail;
    adrNodeG Next;
} NodeG;

typedef struct SuccNodeG
{
    adrNodeG Succ;
    adrSuccNodeG Next;
} SuccNodeG;

typedef struct Graph
{
    adrNodeG First;
} Graph;

/* *** Selektor *** */
#define First(G) G.First
#define Id(Pn) Pn->Id
#define Npred(Pn) Pn->NPred
#define Trail(Pn) Pn->Trail
#define Next(Pn) Pn->Next
#define Succ(Pt) Pt->Succ
#define MapG(Pn) Pn->Map

/* *** Konstruktor *** */
Graph CreateGraph(int X, MATRIKS M);
/* I.S. Sembarang; F.S. Terbentuk Graph dengan satu simpul dengan Id=X */
adrNodeG AlokNodeG(int X, MATRIKS M);
/* Mengembalikan address hasil alokasi Simpul X.*/
/* Jika alokasi berhasil, maka address tidak NilG, misalnya
menghasilkan P, maka Id(P)=X, Npred(P)=0, Trail(P)=NilG,
dan Next(P)=NilG. Jika alokasi gagal, mengembalikan NilG. */
void DealokNodeG(adrNodeG P);
/*I.S. P terdefinisi; F.S. P dikembalikan ke sistem*/

/* *** Manajemen Memory List Successor (Trailer) *** */
adrSuccNodeG AlokSuccNodeG(adrNodeG Pn);
/* Mengembalikan address hasil alokasi. */
/* Jika alokasi berhasil, maka address tidak NilG, misalnya
menghasilkan Pt, maka Succ(Pt)=Pn dan Next(Pt)=NilG. Jika
alokasi gagal, mengembalikan NilG. */
void DealokSuccNodeG(adrSuccNodeG P);
/* I.S. P terdefinisi; F.S. P dikembalikan ke sistem */
adrNodeG SearchNodeG(Graph G, int X);
/*  mengembalikan address simpul dengan Id=X jika sudah ada pada graph G,
NilG jika belum */
adrSuccNodeG SearchEdge(Graph G, int prec, int succ);
/* mengembalikan address trailer yang menyimpan info busur (prec,succ)
jika sudah ada pada graph G, NilG jika belum */
adrNodeG InsertNodeG(Graph G, int X, MATRIKS M);
/* Menambahkan simpul X ke dalam graph, jika alokasi X berhasil. */
/* I.S. G terdefinisi, X terdefinisi dan belum ada pada G. */
/*  F.S. Jika alokasi berhasil, X menjadi elemen terakhir G, Pn berisi
address simpul X. Jika alokasi gagal, G tetap, Pn berisi NilG */
Graph InsertEdge(Graph G, int prec, int succ);
/*  Menambahkan busur dari prec menuju succ ke dalam G  */
/*  I.S. G, prec, succ terdefinisi */
/* F.S. Jika belum ada busur (prec,succ) di G, maka tambahkan busur
(prec,succ) ke G. Jika simpul prec/succ belum ada pada G,
tambahkan simpul tersebut dahulu. Jika sudah ada busur (prec,succ)
di G, maka G tetap.  */

#endif