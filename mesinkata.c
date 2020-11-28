
#include "mesinkar.h"
#include "boolean.h"
#include "mesinkata.h"

boolean EndKata;
Kata CKata;

Kata MakeKata(Kata * C, char * command, int length)
/* Membuat command dengan TabKata = command, dan Length = length*/
{
	//KAMUS
	int i;

	//ALGORITMA

	for (i = 0; i < length; ++i)
	{
		(*C).TabKata[i] = command[i];
	}

	(*C).Length = length;
}

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

void IgnoreBlank(char * filename)
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */
{
	while ((CC == BLANK) || ((filename[0] != ' ') && (CC == BLANKFILE)))
	{
		ADV();
	}
}

void STARTKATA(char * filename){
/* I.S. : CC sembarang 
   F.S. : EndKata = true, dan CC = MARK; 
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
	//KAMUS
	//ALGORITMA
	START(filename);
	//mengabaikan blank sebelum mengakuisisi kata
	IgnoreBlank(filename);
	//Pada model akuisisi versi 1, kata diakuisisi mulai dari karakter pertama,
	//sesudah akhir kata atau karakter pertama pita untuk kata pertama
	if (!EOP){
		EndKata = false;
		SalinKata(filename);
	} else {
		EndKata = true;
	}
}

void ADVKATA(char * filename){
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.		  
   Proses : Akuisisi kata menggunakan procedure SalinKata */
	//KAMUS
	//ALGORITMA
	//mengabaikan blank sebelum mengakuisisi kata
	IgnoreBlank(filename);
	if (!EOP){
		EndKata = false;
		SalinKata(filename);
	} else {
		EndKata = true;
	}
	
}

void SalinKata(char * filename){
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
	//KAMUS
	int idx;
	//ALGORITMA
	idx = 0;//inisialisasi idx
	while (((CC != BLANK) && ((filename[0] == ' ') || (CC != BLANKFILE))) && !EOP){
		//jika melebihi NMax maka kata dipotong, tapi tetap ADV
		if (idx < NMax){
			//menyimpan setiap character pada kata
			CKata.TabKata[idx] = CC;
			idx += 1;
		}	
		ADV();	
	}
	//menyimpan panjang kata
	CKata.Length = idx;
	IgnoreBlank(filename);
}

void STARTKALIMAT(char * filename)
/* I.S. : CC sembarang 
   F.S. : EndKata = true, dan CC = MARK; 
          atau EndKata = false, CKata adalah kalimat yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
{
	START(filename);
	//mengabaikan blank sebelum mengakuisisi kata
	IgnoreBlank(filename);
	//Pada model akuisisi versi 1, kata diakuisisi mulai dari karakter pertama,
	//sesudah akhir kata atau karakter pertama pita untuk kata pertama
	if (!EOP){
		EndKata = false;
		SalinKalimat(filename);
	} else {
		EndKata = true;
	}
}

void ADVKALIMAT(char * filename)
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.     
   Proses : Akuisisi kata menggunakan procedure SalinKalimat */
{
	IgnoreBlank(filename);
	if (!EOP){
		EndKata = false;
		SalinKalimat(filename);
	} else {
		EndKata = true;
	}
}

void SalinKalimat(char * filename)
/* Mengakuisisi kalimat, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kalimat yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
	//KAMUS
	int idx;
	//ALGORITMA
	idx = 0;//inisialisasi idx
	while (((CC != MARKKALIMAT) && ((filename[0] == ' ') || (CC != BLANKFILE))) && !EOP){
		//jika melebihi NMax maka kata dipotong, tapi tetap ADV
		if (idx < NMax){
			//menyimpan setiap character pada kata
			CKata.TabKata[idx] = CC;
			idx += 1;
		}	
		ADV();	
	}
	//menyimpan panjang kata
	CKata.Length = idx;
	IgnoreBlank(filename);
}