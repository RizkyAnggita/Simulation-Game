
#ifndef __UTILS_H__
#define __UTILS_H__

#include "boolean.h"
#include "mesinkata.h"
#include "mesinkar.h"
#include "jam.h"
#include "arraybahan.h"

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

TabBahan FileToListBahan();
/* Membaca file yang berisi nama bahan beserta harganya */
/* Mengembalikan list bahan  */

TabBahan CreateEmptyBahanPlayer(TabBahan ListBahan);
/* Membuat inventory utk penyimpanan bahan player
   Semua val pada elemen list diset ke 0 */

void PrintBahanPlayer(TabBahan ListBahan);
/* I.S. ListBahan terdefinisi 
   F.S Isi dari ListBahan ditampilkan ke layar dengan format "{name}: {qty}"*/

void PrintBuyBahan(TabBahan ListBahan);
/* I.S. ListBahan terdefinisi 
   F.S Isi dari ListBahan ditampilkan ke layar dengan format "{name}: {value}"*/

int PriceBuyBahan(Kata name, int qty, TabBahan ShopBahan);
/* Menghitung harga yang perlu dibayar untuk membeli bahan dengan quantity tertentu 
   Mengembalikan total harga jika bahan yang ingin dibeli pengguna (name) ada di 
   shop bahan
   Jika tidak ada di shop bahan, akan mengembalikan total harga -999*/

void PrintTitle();
/* Menampilkan ke layar pembukaan dari game */

void PrintMainMenu();
/* Menampilkan main menu ke layar */

void PrintMap();
/* Menampilkan map beserta legend ke layar */

void PrintPlayerStat(Kata username);
/* Menampilkan stat utama pemain seperti nama dan money */

void PrintTime(JAM CurrentTime, JAM EndTime, boolean PrepPhase);
/* Menampilkan waktu untuk preparation phase */

void PrintPrepStat(JAM TS);
/* TS = Time Spent */
/* Menampilkan stat khusus preparation phase, total aksi waktu
   dan uang yang dibutuhkan */

void PrintMainQueue();
/* Menampilkan  antrian pengunjung saat main phase*/

#endif