
#include "boolean.h"
#include "graph.h"
#include <stdlib.h>
#include <stdio.h>

adrNodeG AlokNodeG(int X, MATRIKS M)
{
    adrNodeG P = (adrNodeG)malloc(sizeof(NodeG));
    if (P != NilG)
    {
        Id(P) = X;
        MapG(P) = M;
        Npred(P) = 0;
        Trail(P) = NilG;
        Next(P) = NilG;
    }

    return P;
}
/* Mengembalikan address hasil alokasi Simpul X.*/
/* Jika alokasi berhasil, maka address tidak NilG, misalnya
menghasilkan P, maka Id(P)=X, Npred(P)=0, Trail(P)=NilG,
dan Next(P)=NilG. Jika alokasi gagal, mengembalikan NilG. */

/* *** Konstruktor *** */
Graph CreateGraph(int X, MATRIKS M)
{
    Graph P;
    First(P) = AlokNodeG(X, M);

    return P;
}
/* I.S. Sembarang; F.S. Terbentuk Graph dengan satu simpul dengan Id=X */
void DealokNodeG(adrNodeG P)
{
    free(P);
}
/*I.S. P terdefinisi; F.S. P dikembalikan ke sistem*/

/* *** Manajemen Memory List Successor (Trailer) *** */
adrSuccNodeG AlokSuccNodeG(adrNodeG Pn)
{
    adrSuccNodeG P = (adrSuccNodeG)malloc(sizeof(adrSuccNodeG));
    if (Pn != NilG)
    {
        Succ(P) = Pn;
        Next(P) = NilG;
    }

    return P;
}
/* Mengembalikan address hasil alokasi. */
/* Jika alokasi berhasil, maka address tidak NilG, misalnya
menghasilkan Pt, maka Succ(Pt)=Pn dan Next(Pt)=NilG. Jika
alokasi gagal, mengembalikan NilG. */
void DealokSuccNodeG(adrSuccNodeG P)
{
    free(P);
}
/* I.S. P terdefinisi; F.S. P dikembalikan ke sistem */
adrNodeG SearchNodeG(Graph G, int X)
{
    adrNodeG P;
    boolean found = false;

    P = First(G);
    while (P != NilG && !found)
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
        return NilG;
    }
}
/*  mengembalikan address simpul dengan Id=X jika sudah ada pada graph G,
NilG jika belum */
adrSuccNodeG SearchEdge(Graph G, int prec, int succ)
{
    adrNodeG P;
    adrSuccNodeG T;
    boolean found = false;

    P = SearchNodeG(G, prec);

    if (P == NilG)
    {
        return NilG;
    }
    else
    {
        T = Trail(P);
        // di notal dosen harusnya codenya
        // while (Id(T) != prec && T != NilG)
        // tapi T (adrSuccNodeG) ga punya field Id, jadi gw ganti ke P
        while ((T != NilG) && !found)
        {
            if (Id(Succ(T)) != prec)
            {
                found = true;
            } else
            {
                T = Next(T);    
            }
        }

        return T;
    }
}
/* mengembalikan address trailer yang menyimpan info busur (prec,succ)
jika sudah ada pada graph G, NilG jika belum */
adrNodeG InsertNodeG(Graph G, int X, MATRIKS M)
{
    adrNodeG Pn = AlokNodeG(X, M);
    adrNodeG P = First(G);

    if (Pn != NilG)
    {
        while (Next(P) != NilG)
        {
            P = Next(P);
        }
        Next(P) = Pn;
    }

    return Pn;
}
/* Menambahkan simpul X ke dalam graph, jika alokasi X berhasil. */
/* I.S. G terdefinisi, X terdefinisi dan belum ada pada G. */
/*  F.S. Jika alokasi berhasil, X menjadi elemen terakhir G, Pn berisi
address simpul X. Jika alokasi gagal, G tetap, Pn berisi NilG */
Graph InsertEdge(Graph G, int prec, int succ)
{
    adrNodeG precNodeG, succNodeG;
    adrSuccNodeG trail;

    if (SearchEdge(G, prec, succ) == NilG)
    {
        

        trail = Trail(precNodeG);

        if (trail == NilG)
        {
            trail = AlokSuccNodeG(succNodeG);
        } else
        {
            while (Next(trail) != NilG)
            {
                trail = Next(trail);
            }    
            Next(trail) = AlokSuccNodeG(succNodeG);
        }
        
        Npred(succNodeG) = Npred(succNodeG) + 1;
    }

    return G;
}
/*  Menambahkan busur dari prec menuju succ ke dalam G  */
/*  I.S. G, prec, succ terdefinisi */
/* F.S. Jika belum ada busur (prec,succ) di G, maka tambahkan busur
(prec,succ) ke G. Jika simpul prec/succ belum ada pada G,
tambahkan simpul tersebut dahulu. Jika sudah ada busur (prec,succ)
di G, maka G tetap.  */
