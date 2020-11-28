#include "listcommand.h"
#include "utils.h"
#include <stdio.h>

void createEmptyListCommand(TabCommand *T){
    /* Membuat List Kosong */
    int i;

    for (i=IdxMinCommand; i< IdxMaxCommand; i++){
        DurasiCommand(*T,i) = DurasiUndef; 
    }
}

void InsertNewCommand(TabCommand *T, Commtype C){
    /* Memasukkan Command baru (Insert Last pada List Linier)*/
    int i = IdxMinCommand;

    while(i<IdxMaxCommand && DurasiCommand(*T,i)!=DurasiUndef){
        i++;
    }
    
    Command(*T,i) = C.perintah;
    DurasiCommand(*T,i) = C.duration;
    
}

void printCommand(TabCommand T){
    int i = IdxMinCommand;
    while(DurasiCommand(T,i) != DurasiUndef ){
        printf("Command: ");
        PrintKata(Command(T,i));
        printf("\nDurasi: %d\n", DurasiCommand(T,i));
        i++;
        printf("\n");
    }
}

int NbElmtCommand(TabCommand T){
    int i = IdxMinCommand;
    int count = 0;
    while (DurasiCommand(T,i) != DurasiUndef){
        count++;
        i++;
    }
    return count;
}