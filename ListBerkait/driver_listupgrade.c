#include "listupgrade.h"
#include <stdio.h>

int main(){

    ListU L;

    CreateEmptyListU(&L);

    if(IsEmptyListU(L)){
        printf("masih kosong bro!\n");
    }

    Kata A,B;
    A.Length = 4;
    A.TabKata[0] = 'T';
    A.TabKata[1] = 'E';
    A.TabKata[2] = 'S';
    A.TabKata[3] = 'T';

    B.Length = 7;
    B.TabKata[0] = 'U';
    B.TabKata[1] = 'P';
    B.TabKata[2] = 'G';
    B.TabKata[3] = 'R';
    B.TabKata[4] = 'A';
    B.TabKata[5] = 'D';
    B.TabKata[6] = 'E';

    InsVFirstListU(&L, A);
    InsVFirstListU(&L, B);

    addressListU P = FirstListU(L);

    while (P!= NilListU){
        printf("\n");
        PrintKata(InfoListU(P));
        printf("\n");

        P = NextListU(P);
    }


    return 0;
}