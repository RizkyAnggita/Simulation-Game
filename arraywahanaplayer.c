
#include "arraywahanaplayer.h"
#include <stdio.h>
#include <stdlib.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmptyListWP (TabWahanaPlayer * T)
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
/* Proses: Inisialisasi semua elemen tabel T dengan ValUndef */
{
	IdxTypeWP i;
	WahanaPlayer WUndef;

	WUndef = MakeWahanaPlayerUndef();

	for (i = IdxMinWP; i < IdxMaxWP + 1; ++i)
	{
		ElmtWP(*T, i) = WUndef;
	}
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmtListWP (TabWahanaPlayer T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
{
	int eff;
	IdxTypeWP i;
	WahanaPlayer WUndef;

	WUndef = MakeWahanaPlayerUndef();
	eff = 0;
	for (i = IdxMinWP; i < IdxMaxWP + 1; ++i)
	{
		if (TotalPlayW(ElmtWP(T, i)) != TotalPlayW(WUndef))
		{
			eff += 1;
		}
	}

	return eff;
}

int MaxNbElListWP (TabWahanaPlayer T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{
	return IdxMaxWP + 1 - IdxMinWP;
}

/* *** Selektor INDEKS *** */
IdxTypeWP GetFirstIdxListWP (TabWahanaPlayer T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
{
	return IdxMinWP;
}

IdxTypeWP GetLastIdxListWP (TabWahanaPlayer T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
{
	IdxTypeWP i;
	WahanaPlayer WUndef;

	WUndef = MakeWahanaPlayerUndef();
	i = IdxMaxWP;
	while((TotalPlayW(ElmtWP(T, i)) == TotalPlayW(WUndef)) && (i > IdxMinWP))
	{
		i -= 1;
	}

	return i;
}