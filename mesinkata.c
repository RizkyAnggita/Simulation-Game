
#include "mesinkar.h"
#include "boolean.h"
#include "mesinkata.h"

boolean EndKata;
Kata CKata;

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
	while ((CC != BLANK) && !EOP){
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