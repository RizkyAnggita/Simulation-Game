/*
NIM : 13519108
Nama : Nathaniel Jason
Tanggal : 08/10/2020
Topik praktikum : Queue
Deskripsi : Fungsi dan Prosedur prioqueuechar
*/


#include "prioqueuechar.h"
#include <stdio.h>
#include <stdlib.h>


/* ********* Prototype ********* */
boolean IsEmpty (PrioQueueChar Q){
/* Mengirim true jika Q kosong: lihat definisi di atas */
	//KAMUS
	//ALGORITMA
	return ((Head(Q) == Nil) && (Tail(Q) == Nil));
}

boolean IsFull (PrioQueueChar Q){
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
	//KAMUS
	//ALGORITMA
	if (IsEmpty(Q))
	{
		return false;
	} else
	{
		if (Head(Q) < Tail(Q))
		{
			return (Tail(Q) - Head(Q) + 1) == MaxEl(Q);
		} else
		{
			return (Head(Q) - Tail(Q)) == 1;
		}
	}
	

}
int NBElmt (PrioQueueChar Q){
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
	//KAMUS
	//ALGORITMA
	if (IsEmpty(Q)){ 
		return 0;
	}
	else if (Head(Q) == Tail(Q))
	{
		return 1;
	}
	else
	{
		if (Head(Q) < Tail(Q))
		{
			return (Tail(Q) - Head(Q) + 1);
		} else
		{
			return (MaxEl(Q) - Head(Q)) + (Tail(Q) + 1);
		}
	}

}

/* *** Kreator *** */
void MakeEmpty (PrioQueueChar * Q, int Max){
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
	//KAMUS
	//ALGORITMA
	(*Q).T = (infotype *) malloc (Max * sizeof(infotype));
	MaxEl(*Q) = Max;
	Head(*Q) = Nil;
	Tail(*Q) = Nil;
}

/* *** Destruktor *** */
void DeAlokasi(PrioQueueChar * Q){
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
	//KAMUS
	//ALGORITMA
	MaxEl(*Q) = 0;
	free((*Q).T);
}

int IncIdx(int Idx, PrioQueueChar Q)
{
	if (Idx + 1 == MaxEl(Q))
	{
		return 0;
	} else
	{
		return Idx + 1;
	}
}

int DecIdx(int Idx, PrioQueueChar Q)
{
	if (Idx == 0)
	{
		return MaxEl(Q) - 1;
	} else
	{
		return Idx - 1;
	}
}

/* *** Primitif Add/Delete *** */
void Enqueue (PrioQueueChar * Q, infotype X){
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
       TAIL "maju" dengan mekanisme circular buffer; */
	//KAMUS
	int pos, incpos;

	//ALGORITMA
	if (IsEmpty(*Q)){
		Head(*Q) = 0;
		Tail(*Q) = 0;
		InfoHead(*Q) = X;
	}
	else {
		pos = Tail(*Q);
		while ((Prio(Elmt(*Q, pos)) < Prio(X)) && (pos != DecIdx(Head(*Q), Q))){
			incpos = IncIdx(pos, *Q);
			Elmt(*Q, incpos) = Elmt(*Q, pos);
			pos = DecIdx(pos, *Q);
		}

		Tail(*Q) = IncIdx(Tail(*Q), *Q);
		incpos = IncIdx(pos, *Q);
		Elmt(*Q, incpos) = X;
	}
}

void Dequeue (PrioQueueChar * Q, infotype * X){
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
	//KAMUS
	//ALGORITMA
	*X = InfoHead(*Q);
	if (NBElmt(*Q) == 1){
		Head(*Q) = Nil;
		Tail(*Q) = Nil;
	} else {
		Head(*Q) = IncIdx(Head(*Q), *Q);
	}
}
/* Operasi Tambahan */
void PrintPrioQueueChar (PrioQueueChar Q){
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<prio-1> <elemen-1>
...
<prio-n> <elemen-n>
#
*/
	//KAMUS
	int i;
	int pos;
	infotype e;
	//ALGORITMA
	for (int i = 0; i < NBElmt(Q); ++i){
		pos = (Head(Q) + i) % MaxEl(Q);
		e = Elmt(Q, pos);
		printf("%d %c\n", Prio(e), Info(e));
	}
	printf("#\n");
}