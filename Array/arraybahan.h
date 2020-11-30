/* MODUL TABEL INTEGER DENGAN ELEMEN POSITIF */
/* Berisi definisi dan semua primitif pemrosesan tabel integer dengan elemen positif */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit, memori tabel statik */

#ifndef ARRAYBAHAN_H
#define ARRAYBAHAN_H

#include "../ADTLain/boolean.h"
#include "../MesinKata/mesinkata.h"
#include "arraybahan.h"


/*  Kamus Umum */
#define IdxMax 10
/* Indeks maksimum array */
#define IdxMin 0
/* Indeks minimum array */
#define IdxUndef -999  
/* Indeks tak terdefinisi*/
// Value Undef dari Bahan adalah dengan Namenya adalah Kata dengan Tabkata nya adalah "" 
// dan Val nya adalah -999
/* Nilai elemen tak terdefinisi*/

typedef struct {
 	int Val;
	Kata Name;
} Bahan;

#define Name(B) (B).Name
#define Val(B) (B).Val

/* Definisi elemen dan koleksi objek */
typedef int IdxType;  /* type indeks */
typedef Bahan ElType;   /* type elemen tabel */
typedef struct { 
  ElType TI[IdxMax+1]; /* memori tempat penyimpan elemen (container) */
} TabBahan;
/* Indeks yang digunakan [IdxMin..IdxMax] */
/* Indeks ke-0 tidak digunakan */
/* Jika T adalah TabBahan, cara deklarasi dan akses: */
/* Deklarasi : T : TabBahan */
/* Maka cara akses: 
   T[i] untuk mengakses elemen ke-i */
/* Definisi : 
   Tabel kosong: semua elemen bernilai ValUndef
   Definisi elemen pertama : T[i] dengan i=1 */
  
/* ********** SELEKTOR ********** */
#define Elmt(T,i) (T).TI[(i)]

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmptyListBahan (TabBahan * T);
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
/* Proses: Inisialisasi semua elemen tabel T dengan ValUndef */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmtListBahan (TabBahan T);
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
int MaxNbElListBahan (TabBahan T);
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
IdxType GetFirstIdxListBahan (TabBahan T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
IdxType GetLastIdxListBahan (TabBahan T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */




#endif