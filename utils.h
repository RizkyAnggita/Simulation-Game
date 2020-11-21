
#ifndef __UTILS_H__
#define __UTILS_H__

#include "boolean.h"
#include "mesinkata.h"
#include "jam.h"

boolean IsKataSama(Kata K1, Kata K2);
/* Mengembalikan True jika kita sama, false jika tidak */

void CopyKata(Kata K1, Kata *K2);
/* Menyalin kata K1 ke kata K2
   I.S.  : K2 terdefinisi kosong
   F.S.  : K2 memiliki tabkata dan length yang sama dengan K1*/

void PrintKata(Kata K);
/* Menampilkan kata K ke layar*/

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

void PrintPrepStat();
/* Menampilkan stat khusus preparation phase, total aksi waktu
   dan uang yang dibutuhkan */

void PrintMainQueue();
/* Menampilkan  antrian pengunjung saat main phase*/

#endif