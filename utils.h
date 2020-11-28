
#ifndef __UTILS_H__
#define __UTILS_H__

#include "boolean.h"
#include "mesinkata.h"
#include "mesinkar.h"
#include "jam.h"
#include "point.h"
#include "arraybahan.h"
#include "matriks.h"
#include "listcommand.h"
#include "command.h"
#include "wahanagame.h"
#include "bintree.h"

void GetBrsKolFileMap(int * NB, int * NK, char * filename);
/* I.S. NBrs, NKol, terdefinisi dan sembarang, filename adalah nama file map 
   F.S. NBrs adalah jumlah baris pada filemap, begitu jg dengan NKol adalah jumlah kolom*/

MATRIKS FileToMatriks(char * filename);
/* Membaca file yang berisi matriks dan mengembalikan matriks tersebut */

void MovePlayer(MATRIKS Map, char Command, POINT * Loc);
/* I.S. Map adalah matriks map yang akan diubah posisi player nya,
        Command adalah command yg di input pengguna 'w'. 'a'. 's'. 'd'.
        Loc adalah lokasi player sebelumnya 
   F.S. Posisi pemain berubah jika tidak menabrak pagar yaitu char '*',
   		Map dan PlayerLoc akan berubah jika tidak menabrak*/

TabBahan FileToListBahan(char * filename);
/* Membaca file yang berisi nama bahan beserta harganya */
/* Mengembalikan list bahan  */

TabBahan CreateEmptyBahan(TabBahan ListBahan);
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

void FileToListTreeWahana(BinTree * T, char * filename, TabBahan ListBahan);
/* Dipakai jika input dari pita karakter */
/* I.S. CC berisi ‘(‘ */
/* F.S. T terdefinisi */
/* Proses: Membaca isi pita karakter dan membangun pohon secara rekursif, hanya
membutuhkan mesin karakter */

void PrintTitle();
/* Menampilkan ke layar pembukaan dari game */

void PrintMainMenu();
/* Menampilkan main menu ke layar */

void PrintMap(int PlayerMap, POINT PlayerLoc, MATRIKS Map1);
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

TabCommand initArrayCommand();
/* Mengembalikan List/Array Command yang setiap elemen bertipe Commtype */
/* Commtype : < perintah : Kata, duration : integer > */

int findDuration(TabCommand T, Kata K);
	/* Mengembalikan durasi sebuah command jika terdapat di TabCommand */
	/* Jika tidak ada, return DurasiUndef=-999 */

boolean BahanCukup(TabBahan BahanPlayer, TabBahan BahanCost);
/* Mengecek apakah player memiliki bahan yang cukup */

boolean MoneyCukup(int MoneyPlayer, int MoneyCost);
/* Mengecek apakah player memiliki uang yang cukup */

TabBahan AddBahan(TabBahan ListBahan1, TabBahan ListBahan2);
/* Menjumlahkan elemen tiap bahan pada 2 List */
/* Asumsi panjang ListBahan1=ListBahan2 */

#endif