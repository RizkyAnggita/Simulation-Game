
#include "mesinkar.h"
#include "boolean.h"
#include "mesinkata.h"

boolean EndKata;
Kata CKata;

void IgnoreBlank(){
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */
	//KAMUS
	//ALGORITMA
	while (CC == BLANK){
		ADV();
	}
}
void STARTKATA(){
/* I.S. : CC sembarang 
   F.S. : EndKata = true, dan CC = MARK; 
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
	//KAMUS
	//ALGORITMA
	START();
	//mengabaikan blank sebelum mengakuisisi kata
	IgnoreBlank();
	//Pada model akuisisi versi 1, kata diakuisisi mulai dari karakter pertama,
	//sesudah akhir kata atau karakter pertama pita untuk kata pertama
	if (CC != MARK){
		EndKata = false;
		SalinKata();
	} else {
		EndKata = true;
	}
}

void ADVKATA(){
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.		  
   Proses : Akuisisi kata menggunakan procedure SalinKata */
	//KAMUS
	//ALGORITMA
	//mengabaikan blank sebelum mengakuisisi kata
	IgnoreBlank();
	if (CC != MARK){
		EndKata = false;
		SalinKata();
	} else {
		EndKata = true;
	}
	
}

void SalinKata(){
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
	while ((CC != BLANK) && (CC != MARK)){
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
	IgnoreBlank();
}