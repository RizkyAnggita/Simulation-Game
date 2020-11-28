
#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"

/* Manajemen Memory */
addrNode AlokNode(infotypeBinTree X)
{
    addrNode P = malloc(sizeof(Node));
    if (P != NilBinTree)
    {
        Akar(P) = X;
        Left(P) = NilBinTree;
        Right(P) = NilBinTree;
    }
    return P;
}
/* Mengirimkan addrNode hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrNode tidak NilBinTree, dan misalnya menghasilkan P, 
  maka Akar(P) = X, Left(P) = NilBinTree, Right(P)=NilBinTree */
/* Jika alokasi gagal, mengirimkan NilBinTree */
void DealokNode(addrNode P)
{
    free(P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrNode P */

/* *** Konstruktor *** */
BinTree Tree(infotypeBinTree Akar, BinTree L, BinTree R)
{
    BinTree P;
    P = AlokNode(Akar);

    if (P != NilBinTree)
    {
        Left(P) = L;
        Right(P) = R;
    }
    else
    {
        P = NilBinTree;
    }
}
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (NilBinTree) jika alokasi gagal */
void MakeTree(infotypeBinTree Akar, BinTree L, BinTree R, BinTree *P)
{
    (*P) = AlokNode(Akar);
    if (*P != NilBinTree)
    {
        Left(*P) = L;
        Right(*P) = R;
    }
    else
    {
        (*P) = NilBinTree;
    }
}
/* I.S. Akar, L, R terdefinisi. P Sembarang */
/* F.S. Membentuk pohon P dengan Akar(P)=Akar, Left(P)=L, dan Right(P)=R 
		jika alokasi berhasil. P = NilBinTree jika alokasi gagal. */

void PrintTreeLevel(BinTree P, int h, int level)
{
    //KAMUS
    int i;

    //ALGORITMA
    if (!IsTreeEmpty(P))
    {
        for (i = 0; i < h * level; ++i)
        {
            printf(" ");
        }
        PrintKata(Type(Akar(P)));
        printf(" %d", Price(Akar(P)));
        printf(" %d", Capacity(Akar(P)));
        printf(" %d ", DurationW(Akar(P)));
        PrintKata(Description(Akar(P)));
        printf(" %d", MoneyCost(Akar(P)));

        for (i = GetFirstIdxListBahan(BahanCost(Akar(P))); i <= GetLastIdxListBahan(BahanCost(Akar(P))); ++i)
        {
            printf(" ");
            PrintKata(Name(Elmt(BahanCost(Akar(P)), i)));
            printf(" %d", Val(Elmt(BahanCost(Akar(P)), i)));
        }

        printf("\n");

        PrintTreeLevel(Left(P), h, level + 1);
        PrintTreeLevel(Right(P), h, level + 1);
    }
}

void PrintTree(BinTree P, int h)
/* I.S. P terdefinisi, h adalah jarak indentasi (spasi) */
/* F.S. Semua simpul P sudah ditulis dengan indentasi (spasi) */
/* Penulisan akar selalu pada baris baru (diakhiri newline) */
/* Contoh, jika h = 2: 
1) Pohon preorder: (A()()) akan ditulis sbb:
A
2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
A
  B
  C
3) Pohon preorder: (A(B(D()())())(C()(E()()))) akan ditulis sbb:
A
  B
    D
  C
    E
*/
{
    PrintTreeLevel(P, h, 0);
}

/* *** Predikat-Predikat Penting *** */
boolean IsTreeEmpty(BinTree P)
/* Mengirimkan true jika P adalah pohon biner kosong */
{
    return (P == NilBinTree);
}

