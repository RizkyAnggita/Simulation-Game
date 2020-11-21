
#include <stdio.h>
#include "boolean.h"
#include "arraybahan.h"



/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmptyListBahan (TabInt * T){
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
/* Proses: Inisialisasi semua elemen tabel T dengan ValUndef */
	/*KAMUS*/
	IdxType	i;
	Bahan ValUndef;
	/*ALGORITMA*/

	ValUndef.Val = -999;

	for (i = IdxMin; i < IdxMax + 1; i++){
		Elmt(*T, i) = ValUndef;
	}
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmtListBahan (TabInt T){
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
	/*KAMUS*/
	int eff;
	IdxType i;
	Bahan ValUndef; 
	/*ALGORITMA*/

	ValUndef.Val = -999;
	eff = 0;
	for (i = IdxMin; i < IdxMax + 1; i++){
		if (Elmt(T, i).Val != ValUndef.Val){
			eff += 1;
		}
	}
	return eff;
}

int MaxNbElListBahan (TabInt T){
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
	/*KAMUS*/
	/*ALGORITMA*/
	return IdxMax + 1 - IdxMin;
}

IdxType GetFirstIdxListBahan (TabInt T){
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
	/*KAMUS*/
	/*ALGORITMA*/
	return IdxMin;
}
IdxType GetLastIdxListBahan (TabInt T){
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
	/*KAMUS*/
	IdxType i;
	Bahan ValUndef;

	/*ALGORITMA*/
	ValUndef.Val = -999;
	i = IdxMax;
	while (Elmt(T, i).Val == ValUndef.Val){
		i -= 1;
	}
	return i;
}

