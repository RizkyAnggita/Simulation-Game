
#include <stdio.h>

#include "utils.h"

#define ENDL printf("\n")


boolean IsKataSama(Kata K1, Kata K2)
/*Mengembalikan True jika kita sama, false jika tidak*/
{
	//KAMUS
	int i;
	//ALGORITMA
	if (K1.Length == K2.Length)
	{
		for (i = 0; i < K1.Length; ++i)
		{
			if (K1.TabKata[i] != K2.TabKata[i])
			{
				return false;
			}
		}
		return true;
	} else 
	{
		return false;
	}
}

void CopyKata(Kata K1, Kata *K2)
/* Menyalin kata K1 ke kata K2
   I.S.  : K2 terdefinisi kosong
   F.S.  : K2 memiliki TabKata dan Length yang sama dengan K1*/
{
	//KAMUS
	int i;

	//ALGORITMA
	(*K2).Length = K1.Length;
	for (i = 0; i < K1.Length; ++i)
	{
		(*K2).TabKata[i] = K1.TabKata[i];
	}
}

void PrintKata(Kata K)
/* Menampilkan kata K ke layar*/
{
	//KAMUS
	int i;

	//ALGORITMA
	for (i = 0; i < K.Length; ++i)
	{
		printf("%c", K.TabKata[i]);
	}
}

int KataToInteger(Kata K)
/* Mengubah Kata menjadi integer */
{
	//KAMUS
	int val, i, currentNum;

	//ALGORITMA
	val = 0;

	for (i = 0; i < K.Length; ++i)
	{
		currentNum = K.TabKata[i] - '0';
		val = (val * 10) + + currentNum;
	}

	return val;
}

void GetBrsKolFileMatriks(int * NB, int * NK, char * filename)
/* I.S. NBrs, NKol, terdefinisi dan sembarang, filename adalah nama file map 
   F.S. NBrs adalah jumlah baris pada filemap, begitu jg dengan NKol adalah jumlah kolom*/
{
	STARTKATA(filename);
	*NK = CKata.Length;

	*NB = 0;
	while (!EndKata)
	{
		*NB += 1;
		ADVKATA(filename);
	}
}

MATRIKS FileToMatriks(char * filename)
/* Membaca file yang berisi matriks dan mengembalikan matriks tersebut */
{
	//KAMUS
	int i, j, NBrs, NKol;
	MATRIKS Map;

	//ALGORITMA
	GetBrsKolFileMatriks(&NBrs, &NKol, filename);

	MakeMATRIKS(NBrs, NKol, &Map);

	i = GetFirstIdxBrs(Map);

	STARTKATA(filename);
	while (!EndKata)
	{
		for (j = GetFirstIdxKol(Map); j < NKol; ++j)
		{
			ElmtM(Map, i, j) = CKata.TabKata[j];
		}
		i += 1;
		ADVKATA(filename);
	}

	return Map;
}

void MovePlayer(MATRIKS Map, char Command, POINT * Loc)
/* I.S. Map adalah matriks map yang akan diubah posisi player nya,
        Command adalah command yg di input pengguna 'w'. 'a'. 's'. 'd'.
        PlayerLoc adalah lokasi player sebelumnya 
   F.S. Posisi pemain berubah jika tidak menabrak pagar yaitu char '*',
   		Map dan PlayerLoc akan berubah jika tidak menabrak*/
{
	//KAMUS
	POINT NewLoc;

	//ALGORITMA
	switch(Command)
	{
		case 'w':
			NewLoc = PrevY(*Loc);
			break;

		case 'a':
			NewLoc = PrevX(*Loc);
			break;

		case 's':
			NewLoc = NextY(*Loc);
			break;

		case 'd':
			NewLoc = NextX(*Loc);
			break;
	}

	if (ElmtM(Map, Ordinat(NewLoc), Absis(NewLoc)) != '*')
	{
		*Loc = NewLoc;	
	}
}

TabBahan FileToListBahan(char * filename)
/* Membaca file yang berisi nama bahan beserta harganya */
/* Mengembalikan list bahan  */
{
	//KAMUS
	TabBahan ListBahan;
	int i;
	Bahan CBahan;

	//ALGORITMA
	MakeEmptyListBahan(&ListBahan);

	STARTKATA(filename);
	Val(CBahan) = KataToInteger(CKata);
	ADVKATA(filename);
	Name(CBahan) = CKata;

	i = 0;
	while (!EndKata)
	{
		Elmt(ListBahan, i) = CBahan;
		i += 1;

		ADVKATA(filename);
		if (!EndKata)
		{
			Val(CBahan) = KataToInteger(CKata);
			ADVKATA(filename);
			Name(CBahan) = CKata;	
		}
	}

	return ListBahan;
}

TabBahan CreateEmptyBahanPlayer(TabBahan ListBahan)
/* Membuat inventory utk penyimpanan bahan player
   Semua val pada elemen list diset ke 0 */
{
	//KAMUS
	IdxType i;

	//ALGORITMA
	for (i = GetFirstIdxListBahan(ListBahan); i <= GetLastIdxListBahan(ListBahan); ++i)
	{
		Val(Elmt(ListBahan, i)) = 0;
	}

	return ListBahan;
}

void PrintBahanPlayer(TabBahan ListBahan)
/* I.S. ListBahan terdefinisi 
   F.S Isi dari ListBahan ditampilkan ke layar dengan format "{name}: {qty}"*/
{
	//KAMUS
	IdxType i;

	//ALGORITMA

	printf("Inventory Bahan\n");
	printf("List: (Nama): (qty)\n");

	for (i = GetFirstIdxListBahan(ListBahan); i <= GetLastIdxListBahan(ListBahan); ++i)
	{
		printf("    - ");
		PrintKata(Name(Elmt(ListBahan, i)));
		printf(": %d\n", Val(Elmt(ListBahan, i)));
	}
}

void PrintBuyBahan(TabBahan ListBahan)
/* I.S. ListBahan terdefinisi 
   F.S Isi dari ListBahan ditampilkan ke layar dengan format "{name}: {value}"*/
{
	//KAMUS
	IdxType i;

	//ALGORITMA

	printf("Ingin membeli apa?\n");
	printf("List: (Nama): (Harga)\n");

	for (i = GetFirstIdxListBahan(ListBahan); i <= GetLastIdxListBahan(ListBahan); ++i)
	{
		printf("    - ");
		PrintKata(Name(Elmt(ListBahan, i)));
		printf(": %d\n", Val(Elmt(ListBahan, i)));
	}
}

int PriceBuyBahan(Kata name, int qty, TabBahan ShopBahan)
/* Menghitung harga yang perlu dibayar untuk membeli bahan dengan quantity tertentu 
   Mengembalikan total harga jika bahan yang ingin dibeli pengguna (name) ada di 
   shop bahan
   Jika tidak ada di shop bahan, akan mengembalikan total harga -999*/
{
	//KAMUS
	IdxType i;
	boolean found;
	int price;

	//ALGORITMA

	i = GetFirstIdxListBahan(ShopBahan);
	found = false;

	while ((i <= GetLastIdxListBahan(ShopBahan)) && (!found))
	{
		if (IsKataSama(name, Name(Elmt(ShopBahan, i))))
		{
			price = qty * Val(Elmt(ShopBahan, i));
			found = true;
		}

		i += 1;
	}

	if (!found)
	{
		price = -999;
	}

	return price;
}

void PrintTitle()
/*Menampilkan ke layar pembukaan dari game*/
{
	printf("// Welcome to Willy wangky's fum factory!!//");
}

void PrintMainMenu()
/*Menampilkan main menu ke layar*/
{
	printf("// New game / load game / exit? //");
}

void PrintMap(int PlayerMap, POINT PlayerLoc, MATRIKS Map1)
/*Menampilkan map beserta legend ke layar*/
{
	//KAMUS
	indeks i, j;
	MATRIKS Map;
	//ALGORITMA
	//Menampilkan map 

	Map = Map1;

	for (i = GetFirstIdxBrs(Map); i <= GetLastIdxBrs(Map); ++i){
		for (j = GetFirstIdxKol(Map); j <= GetLastIdxKol(Map); ++j){
			if ((i == Ordinat(PlayerLoc)) && (j == Absis(PlayerLoc)))
			{
				printf(" P");	
			} else {
				printf(" %c", ElmtM(Map, i, j));	
			}
			
		}
		if (i != GetLastIdxBrs(Map)){
			printf("\n");
		}
	}
	ENDL;

	//Menampilkan legend
	printf("Legend:\n");
	printf("A = Antrian\n");
	printf("P = Player\n");
	printf("W = Wahana\n");
	printf("O = Office\n");
	printf("<, ^, >, v = Gerbang");
}

void PrintPlayerStat(Kata username)
/* Menampilkan stat utama pemain seperti nama, money, dan time */
{
	printf("Name: ");
	PrintKata(username);
	ENDL;

	printf("Money: 1000");
}

void PrintTime(JAM CurrentTime, JAM EndTime, boolean PrepPhase)
/* Menampilkan waktu untuk preparation phase */
{
	//KAMUS
	JAM TR; // TR = Time Remaining

	//ALGORITMA
	printf("Current Time: ");
	TulisJAM(CurrentTime);
	ENDL;

	if (PrepPhase)
	{
		printf("Opening Time: ");
	} else
	{
		printf("Closing Time: ");
	}
	TulisJAM(EndTime);
	ENDL;

	TR = DetikToJAM(Durasi(CurrentTime, EndTime));
	printf("Time Remaining: %d hour(s) %d minute(s) %d second(s)", Hour(TR), Minute(TR), Second(TR));
}

void PrintPrepStat(JAM TS)
/* TS = Time Spent */
/* Menampilkan stat khusus preparation day, total aksi waktu
   dan uang yang dibutuhkan */
{
	printf("Total aksi yang akan dilakukan: 1\n");

	printf("Total waktu yang dibutuhkan: %d hour(s) %d minute(s) %d second(s)", Hour(TS), Minute(TS), Second(TS));
	ENDL;

	printf("Total uang yang dibutuhkan: 60");
}

void PrintMainQueue()
/* Menampilkan  antrian pengunjung saat main phase*/
{
	printf("Antrian [1/5]:\n");
	printf("(Wangky's Universe), Kesabaran: 5");
}

TabCommand initArrayCommand(){
	/* Mengembalikan List/Array Command yang setiap elemen bertipe Commtype */
	/* Commtype : < perintah : Kata, duration : integer > */
	TabCommand T;
	createEmptyListCommand(&T);
	InitGameCommand();
	InsertNewCommand(&T, makeCommtype(CNew, 0));
    InsertNewCommand(&T, makeCommtype(CLoad, 0));
    InsertNewCommand(&T, makeCommtype(CExit, 0));
    InsertNewCommand(&T, makeCommtype(CW, 1));
    InsertNewCommand(&T, makeCommtype(CA, 1));
    InsertNewCommand(&T, makeCommtype(CS, 1));
    InsertNewCommand(&T, makeCommtype(CD, 1));
    InsertNewCommand(&T, makeCommtype(CBuild, 3));
    InsertNewCommand(&T, makeCommtype(CUpgrade, 3));
    InsertNewCommand(&T, makeCommtype(CBuy, 3));
    InsertNewCommand(&T, makeCommtype(CUndo, 0));
    InsertNewCommand(&T, makeCommtype(CExecute, 0));
    InsertNewCommand(&T, makeCommtype(CMain, 0));
    InsertNewCommand(&T, makeCommtype(CServe, 2));
    InsertNewCommand(&T, makeCommtype(CRepair, 5));
    InsertNewCommand(&T, makeCommtype(CDetail, 0));
    InsertNewCommand(&T, makeCommtype(COffice, 0));
    InsertNewCommand(&T, makeCommtype(CPrepare, 0));

	return T;
}


int findDuration(TabCommand T, Kata K){
	/* Mengembalikan durasi sebuah command jika terdapat di TabCommand */
	/* Jika tidak ada, return DurasiUndef=-999 */
    IdxType i = IdxMinCommand;
    boolean found = false;
    
    while (i<NbElmtCommand(T) && !found){
        if(IsKataSama(Command(T,i), K)){
            found = true;
        }
        else{
            i++;
        }
    }
    if (found) {return DurasiCommand(T,i);}
    else {return DurasiUndef;}
}
