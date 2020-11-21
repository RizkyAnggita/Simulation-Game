/* MODUL TABEL INTEGER DENGAN ELEMEN POSITIF */
/* Berisi definisi dan semua primitif pemrosesan tabel integer dengan elemen positif */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit, memori tabel statik */

#ifndef ARRAYBAHAN_H
#define ARRAYBAHAN_H

#include "boolean.h"


/*  Kamus Umum */
#define IdxMax 10
/* Indeks maksimum array */
#define IdxMin 0
/* Indeks minimum array */
#define IdxUndef -999  
/* Indeks tak terdefinisi*/
// Value Undef dari Bahan adalah dengan Namenya adalah "" dan Val nya adalah -999
/* Nilai elemen tak terdefinisi*/

#define NMaxBahan 20

typedef struct {
 	int Val;
	char Name[NMaxBahan];
} Bahan;

/* Definisi elemen dan koleksi objek */
typedef int IdxType;  /* type indeks */
typedef Bahan ElType;   /* type elemen tabel */
typedef struct { 
  ElType TI[IdxMax+1]; /* memori tempat penyimpan elemen (container) */
} TabInt;
/* Indeks yang digunakan [IdxMin..IdxMax] */
/* Indeks ke-0 tidak digunakan */
/* Jika T adalah TabInt, cara deklarasi dan akses: */
/* Deklarasi : T : TabInt */
/* Maka cara akses: 
   T[i] untuk mengakses elemen ke-i */
/* Definisi : 
   Tabel kosong: semua elemen bernilai ValUndef
   Definisi elemen pertama : T[i] dengan i=1 */
  
/* ********** SELEKTOR ********** */
#define Elmt(T,i) (T).TI[(i)]

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty (TabInt * T);
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
/* Proses: Inisialisasi semua elemen tabel T dengan ValUndef */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabInt T);
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
int MaxNbEl (TabInt T);
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabInt T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
IdxType GetLastIdx (TabInt T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabInt T, IdxType i);
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean IsIdxEff (TabInt T, IdxType i);
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */



#endif