#include <stdio.h>
#include <stdlib.h>
#include "matriks.h"
#include "../ADTLain/boolean.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M){
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
	//KAMUS
	//ALGORITMA
	NBrsEff(*M) = NB;
	NKolEff(*M) = NK;
}

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j){
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
	//KAMUS
	boolean IsBrsValid, IsKolValid;
	//ALGORITMA
	IsBrsValid = (i >= BrsMin) && (i <= BrsMax);
	IsKolValid = (j >= KolMin) && (j <= KolMax);
	return IsBrsValid && IsKolValid;

}

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M){
/* Mengirimkan indeks baris terkecil M */
	//KAMUS
	//ALGORITMA
	return BrsMin;
}

indeks GetFirstIdxKol (MATRIKS M){
/* Mengirimkan indeks kolom terkecil M */
	//KAMUS
	//ALGORITMA
	return KolMin;
}

indeks GetLastIdxBrs (MATRIKS M){
/* Mengirimkan indeks baris terbesar M */
	//KAMUS
	//ALGORITMA
	return NBrsEff(M) - 1;
}

indeks GetLastIdxKol (MATRIKS M){
/* Mengirimkan indeks kolom terbesar M */
	//KAMUS
	//ALGORITMA
	return NKolEff(M) - 1;
}

boolean IsIdxEff (MATRIKS M, indeks i, indeks j){
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
	//KAMUS
	boolean IsBrsValid, IsKolValid;
	//ALGORITMA
	IsBrsValid = (i >= GetFirstIdxBrs(M)) && (i <= GetLastIdxBrs(M));
	IsKolValid = (j >= GetFirstIdxKol(M)) && (j <= GetLastIdxKol(M));
	return IsBrsValid && IsKolValid;
}


// /* ********** Assignment  MATRIKS ********** */
// void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl){
// /* Melakukan assignment MHsl  MIn */
// 	//KAMUS
// 	indeks i, j;
// 	//ALGORITMA
// 	MakeMATRIKS(NBrsEff(MIn), NKolEff(MIn), MHsl);
// 	for (i = GetFirstIdxBrs(MIn); i <= GetLastIdxBrs(MIn); ++i){
// 		for (j = GetFirstIdxKol(MIn); j <= GetLastIdxKol(MIn); ++j){
// 			Elmt(*MHsl, i, j) = Elmt(MIn, i, j);
// 		}
// 	}
// }

/* ********** KELOMPOK BACA/TULIS ********** */
void TulisMATRIKS (MATRIKS M){
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
	//KAMUS
	indeks i, j;
	//ALGORITMA
	for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); ++i){
		for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); ++j){
			printf(" %c", ElmtM(M, i, j));
		}
		if (i != GetLastIdxBrs(M)){
			printf("\n");
		}
	}

}
// void MakeMAP(MATRIKS *M){
//     MakeMATRIKS(7,7,M);
//     for (indeks i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); ++i){
// 		for (indeks j = GetFirstIdxKol(*M); j <= GetLastIdxKol(*M); ++j){
// 			if (i==GetFirstIdxBrs(*M) || i==GetLastIdxBrs(*M) || j==GetFirstIdxKol(*M) || j==GetLastIdxKol(*M)){
//                 Elmt(*M,i,j)='*';
// 			}
// 			else{
//                 Elmt(*M,i,j)='-';
// 			}
// 		}
// 	}
// }


// void TulisMAPFile(MATRIKS M){
//     MakeMAP(&M);
//     FILE *Mfile;
// 	Mfile=fopen("matriks.txt","w");
// 	for (indeks i=GetFirstIdxBrs(M);i<=GetLastIdxBrs(M);i++){
//         char a[100];
//         for (indeks j=GetFirstIdxKol(M);j<=GetLastIdxKol(M);j++){
//             a[j]=Elmt(M,i,j);
//         }
//         fprintf(Mfile,a);
//         fprintf(Mfile,"\n");
// 	}
// 	fclose(Mfile);
// }
