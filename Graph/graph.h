/* ADT Graph */

#ifndef _GRAPH_H_
#define _GRAPH_H_

/* Modul lain yang digunakan : */

#include "listrek.h"
#include "boolean.h"

#define Nil NULL

/* Definisi Type */
typedef struct Node *adrNode;
typedef struct SuccNode *adrSuccNode;

typedef struct Node
{
    int Id;
    int NPred;
    adrSuccNode Trail;
    adrNode Next;
} Node;

typedef struct SuccNode
{
    adrNode Succ;
    adrSuccNode Next;
} SuccNode;

typedef struct Graph
{
    adrNode First;
} Graph;

/* *** Selektor *** */
#define First(G) G.First
#define Id(Pn) Pn->Id
#define Npred(Pn) Pn->NPred
#define Trail(Pn) Pn->Trail
#define Next(Pn) Pn->Next
#define Succ(Pt) Pt->Succ
#define Next(Pt) Pt->Next

/* *** Konstruktor *** */
Graph CreateGraph(infotype X);
/* I.S. Sembarang; F.S. Terbentuk Graph dengan satu simpul dengan Id=X */
adrNode AlokNode(infotype X);
/* Mengembalikan address hasil alokasi Simpul X.*/
/* Jika alokasi berhasil, maka address tidak Nil, misalnya
menghasilkan P, maka Id(P)=X, Npred(P)=0, Trail(P)=Nil,
dan Next(P)=Nil. Jika alokasi gagal, mengembalikan Nil. */
void DealokNode(adrNode P);
/*I.S. P terdefinisi; F.S. P dikembalikan ke sistem*/

/* *** Manajemen Memory List Successor (Trailer) *** */
adrSuccNode AlokSuccNode(adrNode Pn);
/* Mengembalikan address hasil alokasi. */
/* Jika alokasi berhasil, maka address tidak Nil, misalnya
menghasilkan Pt, maka Succ(Pt)=Pn dan Next(Pt)=Nil. Jika
alokasi gagal, mengembalikan Nil. */
void DealokSuccNode(adrSuccNode P);
/* I.S. P terdefinisi; F.S. P dikembalikan ke sistem */
adrNode SearchNode(Graph G, infotype X);
/*  mengembalikan address simpul dengan Id=X jika sudah ada pada graph G,
Nil jika belum */
adrSuccNode SearchEdge(Graph G, infotype prec, infotype succ);
/* mengembalikan address trailer yang menyimpan info busur (prec,succ)
jika sudah ada pada graph G, Nil jika belum */
adrNode InsertNode(Graph G, infotype X);
/* Menambahkan simpul X ke dalam graph, jika alokasi X berhasil. */
/* I.S. G terdefinisi, X terdefinisi dan belum ada pada G. */
/*  F.S. Jika alokasi berhasil, X menjadi elemen terakhir G, Pn berisi
address simpul X. Jika alokasi gagal, G tetap, Pn berisi Nil */
Graph InsertEdge(Graph G, infotype prec, infotype succ);
/*  Menambahkan busur dari prec menuju succ ke dalam G  */
/*  I.S. G, prec, succ terdefinisi */
/* F.S. Jika belum ada busur (prec,succ) di G, maka tambahkan busur
(prec,succ) ke G. Jika simpul prec/succ belum ada pada G,
tambahkan simpul tersebut dahulu. Jika sudah ada busur (prec,succ)
di G, maka G tetap.  */
Graph DeleteNode(Graph G, infotype X);
/*  Menghapus simpul X dari G  */
/* I.S. G terdefinisi, X terdefinisi dan ada pada G, jumlah simpul
pada G lebih dari 1 */
/* F.S. simpul X dan semua busur yang terhubung ke X dihapus
dari G. */
#endif