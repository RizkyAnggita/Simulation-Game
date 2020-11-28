#include "listrek.h"
#include "boolean.h"
#include "graph.h"
#include <stdlib.h>
#include <stdio.h>

/* *** Konstruktor *** */
Graph CreateGraph(infotype X)
{
    Graph P;
    First(P) = X;

    return P;
}
/* I.S. Sembarang; F.S. Terbentuk Graph dengan satu simpul dengan Id=X */
adrNode AlokNode(infotype X)
{
    adrNode P = (adrNode)malloc(sizeof(adrNode));
    if (P != Nil)
    {
        Id(P) = X;
        Npred(P) = 0;
        Trail(P) = Nil;
        Next(P) = Nil;
    }

    return P;
}
/* Mengembalikan address hasil alokasi Simpul X.*/
/* Jika alokasi berhasil, maka address tidak Nil, misalnya
menghasilkan P, maka Id(P)=X, Npred(P)=0, Trail(P)=Nil,
dan Next(P)=Nil. Jika alokasi gagal, mengembalikan Nil. */
void DealokNode(adrNode P)
{
    free(P);
}
/*I.S. P terdefinisi; F.S. P dikembalikan ke sistem*/

/* *** Manajemen Memory List Successor (Trailer) *** */
adrSuccNode AlokSuccNode(adrNode Pn)
{
    adrSuccNode P = (adrSuccNode)malloc(sizeof(adrSuccNode));
    if (Pn != Nil)
    {
        Succ(P) = Pn;
        Next(P) = Nil;
    }

    return P;
}
/* Mengembalikan address hasil alokasi. */
/* Jika alokasi berhasil, maka address tidak Nil, misalnya
menghasilkan Pt, maka Succ(Pt)=Pn dan Next(Pt)=Nil. Jika
alokasi gagal, mengembalikan Nil. */
void DealokSuccNode(adrSuccNode P)
{
    free(P);
}
/* I.S. P terdefinisi; F.S. P dikembalikan ke sistem */
adrNode SearchNode(Graph G, infotype X)
{
    adrNode P;
    boolean found = false;

    P = First(G);
    while (P != Nil && !found)
    {
        if (Id(P) == X)
        {
            found = true;
        }
        else
        {
            P = Next(P);
        }
    }

    if (found)
    {
        return P;
    }
    else
    {
        return Nil;
    }
}
/*  mengembalikan address simpul dengan Id=X jika sudah ada pada graph G,
Nil jika belum */
adrSuccNode SearchEdge(Graph G, infotype prec, infotype succ)
{
    adrNode P;
    adrSuccNode T;
    boolean found = false;

    P = SearchNode(G, prec);

    if (P == Nil)
    {
        return Nil;
    }
    else
    {
        T = Trail(P);
        // di notal dosen harusnya codenya
        // while (Id(T) != prec && T != Nil)
        // tapi T (adrSuccNode) ga punya field Id, jadi gw ganti ke P
        while (Id(P) != prec && T != Nil)
        {
            T = Next(T);
        }

        return T;
    }
}
/* mengembalikan address trailer yang menyimpan info busur (prec,succ)
jika sudah ada pada graph G, Nil jika belum */
adrNode InsertNode(Graph G, infotype X)
{
    adrNode Pn = AlokNode(X);
    adrNode P = First(G);

    if (Pn != Nil)
    {
        while (Next(P) != Nil)
        {
            P = Next(P);
        }
        Next(P) = Pn;
    }
}
/* Menambahkan simpul X ke dalam graph, jika alokasi X berhasil. */
/* I.S. G terdefinisi, X terdefinisi dan belum ada pada G. */
/*  F.S. Jika alokasi berhasil, X menjadi elemen terakhir G, Pn berisi
address simpul X. Jika alokasi gagal, G tetap, Pn berisi Nil */
Graph InsertEdge(Graph G, infotype prec, infotype succ)
{
    adrNode precNode, succNode;
    adrSuccNode trail;

    if (SearchEdge(G, prec, succ) == Nil)
    {
        precNode = SearchNode(G, prec);
        if (precNode = Nil)
        {
            precNode = InsertNode(G, prec);
        }

        succNode = SearchNode(G, succ);

        if (succNode == Nil)
        {
            succNode = InsertNode(G, succ);
        }

        trail = Trail(precNode);

        while (Next(trail) != Nil)
        {
            trail = Next(trail);
        }

        Next(trail) = AlokSuccNode(succNode);
        Npred(succNode) = Npred(succNode) + 1;
    }
}
/*  Menambahkan busur dari prec menuju succ ke dalam G  */
/*  I.S. G, prec, succ terdefinisi */
/* F.S. Jika belum ada busur (prec,succ) di G, maka tambahkan busur
(prec,succ) ke G. Jika simpul prec/succ belum ada pada G,
tambahkan simpul tersebut dahulu. Jika sudah ada busur (prec,succ)
di G, maka G tetap.  */
Graph DeleteNode(Graph G, infotype X)
{
    adrNode P = SearchNode(G, X);
    while (P != Nil)
    {
        Dealokasi(P);
        P = SearchNode(G, X);
    }
}
/*  Menghapus simpul X dari G  */
/* I.S. G terdefinisi, X terdefinisi dan ada pada G, jumlah simpul
pada G lebih dari 1 */
/* F.S. simpul X dan semua busur yang terhubung ke X dihapus
dari G. */