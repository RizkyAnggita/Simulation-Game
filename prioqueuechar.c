
#include "prioqueuechar.h"
#include <stdio.h>
#include <stdlib.h>


/* ********* Prototype ********* */
boolean IsEmptyPQ (PrioQueueChar Q)
{
/* Mengirim true jika Q kosong: lihat definisi di atas */
	//KAMUS
	//ALGORITMA
	return ((Head(Q) == NilPQ) && (Tail(Q) == NilPQ));
}

boolean IsFullPQ (PrioQueueChar Q){
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxElPQ */
	//KAMUS
	//ALGORITMA
	if (IsEmptyPQ(Q))
	{
		return false;
	} else
	{
		if (Head(Q) < Tail(Q))
		{
			return (Tail(Q) - Head(Q) + 1) == MaxElPQ(Q);
		} else
		{
			return (Head(Q) - Tail(Q)) == 1;
		}
	}
	

}
int NBElmtPQ (PrioQueueChar Q){
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
	//KAMUS
	//ALGORITMA
	if (IsEmptyPQ(Q)){ 
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
			return (MaxElPQ(Q) - Head(Q)) + (Tail(Q) + 1);
		}
	}

}

/* *** Kreator *** */
void MakeEmptyPQ (PrioQueueChar * Q, int Max){
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max */
/* atau : jika alokasi gagal, Q kosong dg MaxElPQ=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
	//KAMUS
	//ALGORITMA
	(*Q).T = (infotypePQ *) malloc (Max * sizeof(infotypePQ));
	MaxElPQ(*Q) = Max;
	Head(*Q) = NilPQ;
	Tail(*Q) = NilPQ;
}

/* *** Destruktor *** */
void DeAlokasiPQ(PrioQueueChar * Q){
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxElPQ(Q) diset 0 */
	//KAMUS
	//ALGORITMA
	MaxElPQ(*Q) = 0;
	free((*Q).T);
}

int IncIdx(int Idx, PrioQueueChar Q)
{
	if (Idx + 1 == MaxElPQ(Q))
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
		return MaxElPQ(Q) - 1;
	} else
	{
		return Idx - 1;
	}
}

/* *** Primitif Add/Delete *** */
void Enqueue (PrioQueueChar * Q, infotypePQ X){
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
       TAIL "maju" dengan mekanisme circular buffer; */
	//KAMUS
	int pos, incpos;

	//ALGORITMA
	if (IsEmptyPQ(*Q)){
		Head(*Q) = 0;
		Tail(*Q) = 0;
		InfoHead(*Q) = X;
	}
	else {
		pos = Tail(*Q);
		while ((Prio(ElmtPQ(*Q, pos)) < Prio(X)) && (pos != DecIdx(Head(*Q), *Q))){
			incpos = IncIdx(pos, *Q);
			ElmtPQ(*Q, incpos) = ElmtPQ(*Q, pos);
			pos = DecIdx(pos, *Q);
		}

		Tail(*Q) = IncIdx(Tail(*Q), *Q);
		incpos = IncIdx(pos, *Q);
		ElmtPQ(*Q, incpos) = X;
	}
}

void Dequeue (PrioQueueChar * Q, infotypePQ * X){
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = NilPQai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
	//KAMUS
	//ALGORITMA
	*X = InfoHead(*Q);
	if (NBElmtPQ(*Q) == 1){
		Head(*Q) = NilPQ;
		Tail(*Q) = NilPQ;
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
	infotypePQ e;
	//ALGORITMA
	for (int i = 0; i < NBElmtPQ(Q); ++i){
		pos = (Head(Q) + i) % MaxElPQ(Q);
		e = ElmtPQ(Q, pos);
		printf("%d \n", Prio(e));
	}
	printf("#\n");
}