#ifndef __LISTCOMMAND_H__
#define __LISTCOMMAND_H__

#include "mesinkata.h"

typedef int IdxType;  /* type indeks */
#define IdxMaxCommand 49
/* Indeks maksimum array */
#define IdxMinCommand 0
/* Indeks minimum array */
#define DurasiUndef -999  

typedef struct {
    Kata perintah;
    int duration;
}Comm;

typedef Comm Commtype;

typedef struct{
    Commtype TI[IdxMaxCommand];
}TabCommand;

/* Selektor */
#define ElmtCommand(T,i) (T).TI[(i)]
#define Command(T,i) (T).TI[(i)].perintah
#define Durasi(T,i) (T).TI[(i)].duration


void createEmptyListCommand(TabCommand *L);
/* Membuat List Command Kosong */

void InsertNewCommand(TabCommand *L, Commtype C);
/* Memasukkan Command baru (Insert Last pada List Linier)*/

void printCommand(TabCommand L);
/* Mencetak daftar command yang ada */

int NbElmtCommand(TabCommand T);
/* Mereturn banyaknya Command yang ada */



#endif