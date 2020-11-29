
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
#include "listwahanagame.h"
#include "wahanaplayer.h"
#include "arraywahanaplayer.h"
#include "stackins.h"

void GetBrsKolFileMap(int *NB, int *NK, char *filename);
/* I.S. NBrs, NKol, terdefinisi dan sembarang, filename adalah nama file map
   F.S. NBrs adalah jumlah baris pada filemap, begitu jg dengan NKol adalah jumlah kolom*/

MATRIKS FileToMatriks(char *filename);
/* Membaca file yang berisi matriks dan mengembalikan matriks tersebut */

char GetElementMap(MATRIKS Map, POINT Loc);
/* Mengembalikan elemen yang ada pada Map pada koordinat Loc */

void SetElementMap(MATRIKS *Map, POINT Loc, char el);
/* I.S. Map, Loc, el terdefinisi
   F.S. Map pada koordinat Loc, di set element nya menjadi el */

void MovePlayer(MATRIKS Map, char Command, POINT *Loc);
/* I.S. Map adalah matriks map yang akan diubah posisi player nya,
        Command adalah command yg di input pengguna 'w'. 'a'. 's'. 'd'.
        Loc adalah lokasi player sebelumnya
   F.S. Posisi pemain berubah jika tidak menabrak pagar yaitu char '*',
   		Map dan PlayerLoc akan berubah jika tidak menabrak*/

TabBahan FileToListBahan(char *filename);
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

void PitaToTreeWahanaGame(BinTree *T, char *filename, TabBahan ListBahan);
/* Dipakai jika input dari pita karakter */
/* I.S. CC berisi ‘(‘ */
/* F.S. T terdefinisi */
/* Proses: Membaca isi pita karakter dan membangun pohon secara rekursif, hanya
membutuhkan mesin karakter */

ListWG FileToListTreeWahana(char *filename, TabBahan ListBahan);
/* Membaca file wahana yang berisi beberapa tree wahana, setiap tree wahana akan
   di-insert ke List wahana game. Mengembalikan list wahana game */

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

void PrintPrepStat(int Aksi, JAM J, int Money, TabBahan ListBahan);
/* Menampilkan stat khusus preparation phase, total aksi waktu
   dan uang yang dibutuhkan */

void PrintMainQueue();
/* Menampilkan  antrian pengunjung saat main phase*/

void PrintBuildWahana(ListWG ListWahanaGame);
/*  I.S. ListWahana terdefinisi
    F.S. menampilkan list wahana game ke layar */

BinTree FindBasicWahana(ListWG ListWahanaGame, Kata T);
/* Mencari tree wahana basic, dengan type tertentu, yaitu K */

TabCommand InitArrayCommand();
/* Mengembalikan List/Array Command yang setiap elemen bertipe Commtype */
/* Commtype : < perintah : Kata, duration : integer > */

int FindDuration(TabCommand T, Kata K);
/* Mengembalikan durasi sebuah command jika terdapat di TabCommand */
/* Jika tidak ada, return DurasiUndef=-999 */

boolean BahanCukup(TabBahan BahanPlayer, TabBahan BahanCost);
/* Mengecek apakah player memiliki bahan yang cukup */

boolean MoneyCukup(int MoneyPlayer, int MoneyCost);
/* Mengecek apakah player memiliki uang yang cukup */

TabBahan AddBahan(TabBahan ListBahan, Bahan B);
// Menambahkan bahan kepada list bahan, bahan sudah pasti terdefinisi di list bahan 

TabBahan AddListBahan(TabBahan ListBahan1, TabBahan ListBahan2);
/* Menjumlahkan elemen tiap bahan pada 2 List */
/* Asumsi panjang ListBahan1=ListBahan2 */

TabBahan MinusBahan(TabBahan ListBahan, Bahan B);
// Menagurangi bahan kepada list bahan, bahan sudah pasti terdefinisi di list bahan 

TabBahan MinusListBahan(TabBahan ListBahan1, TabBahan ListBahan2);
/* Mengurangi elemen tiap bahan pada  List 1 dengan List 2 */
/* Asumsi panjang ListBahan1=ListBahan2 */

boolean SearchNodeWG (BinTree T, Kata K);
/* Mengirimkan true jika ada node dari T yang memiliki info.Type = K */

addrNode findTypeBinTree(Kata TypeYangDicari, BinTree T);
/* Mengembalikas addrNode dari Node yang memiliki Type sama dengan
TypeYangDicari, kalau tidak ada return NilBinTree */

addrNode FindListWahana(Kata K, ListWG ListWahanaGame);
/* Mencari tree wahana game tertentu dengan type = T, pada suatu list of wahanagame */

Kata GenerateWahanaName(Kata TypeWahana, POINT PlayerLoc, int PlayerMap);
/* Mengenerate Nama Wahana yang unik dari Type(Nama) Wahana Standar berdasarkan
PlayerLoc dan Map */

int PlayerTunnel(int MapIdPlayer, char Symbol);
/* Menghasilkan perpindahan player dari symbol yang dimasukkan */

WahanaPlayer SearchWahanaPlayer(int Map, POINT Loc, TabWahanaPlayer ArrayWP);
/*  I.S. Wahana Player pasti ada
    F.S. Mencari Wahana Player yang memiliki Map dan Loc sama dengan input */

void FindAround(POINT P, MATRIKS MapMat, int MapInt, TabWahanaPlayer ArrayWP);
/*  I.S. Player ada di posisi P di Map MapInt dengan Matriks MapMat 
    F.S. Output daftar semua wahana di sekitar Player
    Jika tidak ada wahana di sekitar player, output pesan "Tidak ada wahana di sekitar anda" */

JAM TimeSkip(JAM Sekarang, TabCommand T, Kata K);
/* Mengembalikan JAM yang sudah di-timeskip setelah menjalankan command */

#endif
