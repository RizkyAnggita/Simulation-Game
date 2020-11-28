
#ifndef __ARRAYWAHANAPLAYER_H__
#define __ARRAYWAHANAPLAYER_H__

#include "wahanaplayer.h"

/*  Kamus Umum */
#define IdxMaxWP 150
/* Indeks maksimum array */
#define IdxMinWP 0
/* Indeks minimum array */
#define IdxUndefWP -999  
/* Indeks tak terdefinisi*/
// Value Undef dari Bahan adalah dengan Namenya adalah Kata dengan Tabkata nya adalah "" 
// dan Val nya adalah -999
/* Nilai elemen tak terdefinisi*/

typedef int IdxTypeWP;
typedef WahanaPlayer ElTypeWP;
typedef struct {
	ElTypeWP TI[IdxMaxWP+1];
} TabWahanaPlayer;

/* Indeks yang digunakan [IdxMin..IdxMax] */
/* Indeks ke-0 tidak digunakan */
/* Jika T adalah TabWahanaPlayer, cara deklarasi dan akses: */
/* Deklarasi : T : TabWahanaPlayer */
/* Maka cara akses: 
   T[i] untuk mengakses elemen ke-i */
/* Definisi : 
   Tabel kosong: semua elemen bernilai ValUndef
   Definisi elemen pertama : T[i] dengan i=1 */

/* ********** SELEKTOR ********** */
#define ElmtWP(T,i) (T).TI[(i)]

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmptyListWP (TabWahanaPlayer * T);
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
/* Proses: Inisialisasi semua elemen tabel T dengan ValUndef */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmtListWP (TabWahanaPlayer T);
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
int MaxNbElListWP (TabWahanaPlayer T);
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
IdxTypeWP GetFirstIdxListWP (TabWahanaPlayer T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
IdxTypeWP GetLastIdxListWP (TabWahanaPlayer T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */

#endif

