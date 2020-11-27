
#include <stdio.h>
#include <stdlib.h>

#include "mesinbahan.h"
#include "mesinkar.h"
#include "mesinkata.h"
#include "boolean.h"
#include "arraybahan.h"

boolean EndBahan;
Bahan CBahan;

void IgnoreBlankBahan()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */
{
	while (CC == BLANK)
	{
		ADV();
	}
}

void STARTBAHAN(char * filename)
/* I.S. : CC sembarang 
   F.S. : EndBahan = true, dan CC = MARK; 
          atau EndBahan = false, CBahan adalah bahan yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir bahan */
{
	START(filename);
	IgnoreBlankBahan();
	if (EOP)
	{
		EndBahan = true;
	} else
	{
		EndBahan = false;
		SalinBahan();
	}
}

void ADVBAHAN()
/* I.S. : CC adalah karakter pertama bahan yang akan diakuisisi 
   F.S. : CKata adalah bahan terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.		  
   Proses : Akuisisi kata menggunakan procedure SalinKata */
{
	IgnoreBlankBahan();
	if (EOP)
	{
		EndBahan = true;
	} else
	{
		EndBahan = false;
		SalinBahan();
	}
	
}

void SalinBahan()
/* Mengakuisisi bahan, menyimpan dalam CBahan
   Format dari pita bahan yang dibaca adalah "{Number} {Name}"
   I.S. : CC adalah karakter pertama dari bahan
   F.S. : CBahan berisi kata yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
	//KAMUS LOKAL
	int idx, NumCC;

	//ALGORITMA
	//Akuisisi bagian number
	CBahan.Val = 0;

	while (CC != BLANK)
	{
		NumCC  = CC - '0';
		CBahan.Val = (CBahan.Val * 10) + NumCC;
		ADV();
	}

	IgnoreBlankBahan();

	idx = 0;

	while ((CC != BLANK) && !EOP)
	{	
		CBahan.Name.TabKata[idx] = CC;
		idx += 1;
		ADV();	
	}
	CBahan.Name.Length = idx;

	IgnoreBlankBahan();

}