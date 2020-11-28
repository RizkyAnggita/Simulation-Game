#include "arraybahan.h"
#include <stdio.h>

int main(){
    Bahan B;

    TabBahan TB;

    MakeEmptyListBahan(&TB);
    printf("NbElmt: %d\n", NbElmtListBahan(TB));  // = 0

    //Masukin bahan manual
    B.Name.TabKata[0] = 'W';
    B.Name.TabKata[1] = 'o';
    B.Name.TabKata[2] = 'o';
    B.Name.TabKata[3] = 'd';
    B.Name.Length = 4;
    B.Val = 10;

    Elmt(TB, 0) = B;
    printf("NbElmt: %d\n", NbElmtListBahan(TB));  // = 1

    //Masukin bahan manual
    B.Name.TabKata[0] = 'C';
    B.Name.TabKata[1] = 'e';
    B.Name.TabKata[2] = 'm';
    B.Name.TabKata[3] = 'e';
    B.Name.TabKata[4] = 'n';
    B.Name.TabKata[5] = 't';

    B.Name.Length = 6;
    B.Val = 15;

    Elmt(TB, 1) = B;
    printf("NbElmt: %d\n", NbElmtListBahan(TB));  // = 2  

    int a = Elmt(TB,0).Name.Length;
    int i; 

    //Mencetak Nama Bahan di indeks-0
    printf("Nama Bahan ke-0: ");
    for (i=0; i< a; i++){
        printf("%c", Elmt(TB,0).Name.TabKata[i]);
    }
    printf("\n");
    printf("Jumlah Bahan ke-0: %d\n", Elmt(TB,0).Val);

    printf("Max NbElListBahan: %d\n", MaxNbElListBahan(TB));
    printf("LastIdxListBahan : %d\n", GetLastIdxListBahan(TB));
    printf("FirstIdxListBahan: %d\n", GetFirstIdxListBahan(TB));


    return 0;
}