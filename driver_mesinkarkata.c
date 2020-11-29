/* Driver ADT mesinkar dan mesinkata */

#include "mesinkar.h"
#include "mesinkata.h"
#include <stdio.h>

int main(){
    
    int i;

    Kata Cnew;
    char command[3] = "new";
    MakeKata(&Cnew, command, 3);
    

    //Baca yang tanpa file
    STARTKATA(" ");
    printf("\n");

    while (!EOP)
    {
        for(i=0; i< CKata.Length; i++){
            printf("%c", CKata.TabKata[i]); //Manual
        }
        printf("\nPrintKata: ");
        PrintKata(CKata); // Otomatis
        if (IsKataSama(CKata, Cnew )){
            printf("\nwow kata yang anda masukkan adalah 'new' \n");
        }
        printf("\n");
        ADVKATA(" ");
    }

    Kata B;
    CopyKata(Cnew, &B);
    if (IsKataSama(Cnew, B)){
        printf("Copy kata berhasil\n");
    }

    Kata Angka;
    char angka[3] = "159";
    MakeKata(&Angka, angka, 3);

    int Kata2Angka = KataToInteger(Angka);
    printf("Angka: %d\n", Kata2Angka);

    return 0;
}