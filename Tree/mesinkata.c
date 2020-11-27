/*
NIM : 13519048
Nama : Ariya Adinatha
Tanggal : 30 Sept 2020
Topik praktikum : Mesin Kata
Deskripsi : implementasi dari mesinkata.h
*/

#include "mesinkar.h"
#include "boolean.h"
#include "mesinkata.h"
#include <stdio.h>
#include <stdlib.h>

#define NMax 50
#define BLANK ' '

/* State Mesin Kata */
boolean EndKata = false;
Kata CKata;

void IgnoreBlank()
{
    while (CC == BLANK && CC != MARK)
    {
        ADV();
    };
}
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */

void STARTKATA()
{
    START();
    IgnoreBlank();
    if (CC == MARK)
    {
        EndKata = true;
    }
    else
    {
        EndKata = false;
        SalinKata();
    }
}
/* I.S. : CC sembarang 
   F.S. : EndKata = true, dan CC = MARK; 
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

void ADVKATA()
{
    IgnoreBlank();
    if (CC == MARK)
    {
        EndKata = true;
    }
    else
    {
        SalinKata();
    }
}
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.		  
   Proses : Akuisisi kata menggunakan procedure SalinKata */

void SalinKata()
{
    while (CC != BLANK && CC != MARK && CKata.Length < NMax)
    {
        CKata.TabKata[CKata.Length] = CC;
        CKata.Length += 1;
        ADV();
    }
}
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
