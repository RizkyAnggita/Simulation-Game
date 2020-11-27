#include "listcommand.h"
#include <stdio.h>

void createEmptyListCommand(TabCommand *T){
    /* Membuat List Kosong */
    IdxType i;

    for (i=IdxMinCommand; i< IdxMaxCommand; i++){
        Durasi(*T,i) = DurasiUndef; 
    }
}

void InsertNewCommand(TabCommand *T, Commtype C){
    /* Memasukkan Command baru (Insert Last pada List Linier)*/
    IdxType i = IdxMinCommand;

    while(i<IdxMaxCommand && Durasi(*T,i)!=DurasiUndef){
        i++;
    }
    
    Command(*T,i) = C.perintah;
    Durasi(*T,i) = C.duration;
    
}

void printCommand(TabCommand T){
    IdxType i = IdxMinCommand;
    while(Durasi(T,i) != DurasiUndef ){
        printf("Command: ");
        PrintKataC(Command(T,i));
        printf("\nDurasi: %d\n", Durasi(T,i));
        i++;
    }
}

int NbElmtCommand(TabCommand T){
    IdxType i = IdxMinCommand;
    int count = 0;
    while (Durasi(T,i) != DurasiUndef){
        printf("AAA\n");
        count++;
        i++;
    }
    return count;
}