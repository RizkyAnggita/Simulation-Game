/* Mesin Bahan */

#ifndef __MESINBAHAN_H__
#define __MESINBAHAN_H__

#include "boolean.h"
#include "mesinkar.h"
#include "mesinkata.h"
#include "arraybahan.h"

#define BLANK ' '


/* State Mesin Kata */
extern boolean EndBahan;
extern Bahan CBahan;

void IgnoreBlankBahan();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */

void STARTBAHAN(char * filename);
/* I.S. : CC sembarang 
   F.S. : EndBahan = true, dan CC = MARK; 
          atau EndBahan = false, CBahan adalah bahan yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir bahan */

void ADVBAHAN();
/* I.S. : CC adalah karakter pertama bahan yang akan diakuisisi 
   F.S. : CKata adalah bahan terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.		  
   Proses : Akuisisi kata menggunakan procedure SalinKata */

void SalinBahan();
/* Mengakuisisi bahan, menyimpan dalam CBahan
   Format dari pita bahan yang dibaca adalah "{Number} {Name}"
   I.S. : CC adalah karakter pertama dari bahan
   F.S. : CBahan berisi kata yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

#endif