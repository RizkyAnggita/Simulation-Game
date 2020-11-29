/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "boolean.h"
#include "mesinkar.h"
#include <stdio.h>

#define NMax 50
#define BLANK ' '
#define BLANKFILE '\n'
#define MARKKALIMAT ';'

typedef struct {
	char TabKata[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
    int Length;
} Kata;

/* State Mesin Kata */
extern boolean EndKata;
extern Kata CKata;

void MakeKata(Kata * C, char * command, int length);
/* Membuat command dengan TabKata = command, dan Length = length*/

boolean IsKataSama(Kata K1, Kata K2);
/* Mengembalikan True jika kita sama, false jika tidak */

void CopyKata(Kata K1, Kata *K2);
/* Menyalin kata K1 ke kata K2
   I.S.  : K2 terdefinisi kosong
   F.S.  : K2 memiliki tabkata dan length yang sama dengan K1*/

void PrintKata(Kata K);
/* Menampilkan kata K ke layar*/

int KataToInteger(Kata K);
/* Mengubah Kata menjadi integer */

void IgnoreBlank(char * filename);
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */

void STARTKATA(char * filename);
/* I.S. : CC sembarang 
   F.S. : EndKata = true, dan CC = MARK; 
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

void ADVKATA(char * filename);
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.		  
   Proses : Akuisisi kata menggunakan procedure SalinKata */

void SalinKata(char * filename);
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void STARTKALIMAT(char * filename);
/* I.S. : CC sembarang 
   F.S. : EndKata = true, dan CC = MARK; 
          atau EndKata = false, CKata adalah kalimat yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

void ADVKALIMAT(char * filename);
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.     
   Proses : Akuisisi kata menggunakan procedure SalinKalimat */

void SalinKalimat(char * filename);
/* Mengakuisisi kalimat, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kalimat yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

#endif

