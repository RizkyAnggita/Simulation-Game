/* ADT Pohon Biner */
/* Implementasi dengan menggunakan pointer */
/* Penamaan type infotypeBinTree, type addrNode, dan beberapa fungsi disesuikan 
   karena melibatkan modul list rekursif. */

#ifndef _BINTREE_H_
#define _BINTREE_H_

/* Modul lain yang digunakan : */
#include "boolean.h"
#include "mesinkar.h"
#include "mesinkata.h"
#include "wahanagame.h"
#include "utils.h"

#define NilBinTree NULL

/* *** Definisi Type Pohon Biner *** */
/* typedef int infotypeBinTree; */ /* type infotypeBinTree sesuai pada modul listrek */
typedef WahanaGame infotypeBinTree; 
typedef struct tNode *addrNode;
typedef struct tNode
{
   infotypeBinTree info;
   addrNode left;
   addrNode right;
} Node;

/* Definisi PohonBiner : */
/* Pohon Biner kosong : P = NilBinTree */
typedef addrNode BinTree;

/* *** PROTOTYPE *** */

/* *** Selektor *** */
#define Akar(P) (P)->info
#define Left(P) (P)->left
#define Right(P) (P)->right


/* *** Konstruktor *** */
BinTree Tree(infotypeBinTree Akar, BinTree L, BinTree R);
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (NilBinTree) jika alokasi gagal */
void MakeTree(infotypeBinTree Akar, BinTree L, BinTree R, BinTree *P);
/* I.S. Akar, L, R terdefinisi. P Sembarang */
/* F.S. Membentuk pohon P dengan Akar(P)=Akar, Left(P)=L, dan Right(P)=R 
		jika alokasi berhasil. P = NilBinTree jika alokasi gagal. */

/* Manajemen Memory */
addrNode AlokNode(infotypeBinTree X);
/* Mengirimkan addrNode hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrNode tidak NilBinTree, dan misalnya menghasilkan P, 
  maka Akar(P) = X, Left(P) = NilBinTree, Right(P)=NilBinTree */
/* Jika alokasi gagal, mengirimkan NilBinTree */
void DealokNode(addrNode P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrNode P */

/* *** Predikat-Predikat Penting *** */
boolean IsTreeEmpty(BinTree P);
/* Mengirimkan true jika P adalah pohon biner kosong */

void PrintTree(BinTree P, int h);
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

void BuildTree(BinTree *T, char * filename);
/* Dipakai jika input dari pita karakter */
/* I.S. CC berisi ‘(‘ */
/* F.S. T terdefinisi */
/* Proses: Membaca isi pita karakter dan membangun pohon secara rekursif, hanya
membutuhkan mesin karakter */

#endif