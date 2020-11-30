#include "matriks.h"
#include <stdio.h>

int main(){
    MATRIKS M1, M2;
    int NB, NK;
    NB = 3;
    NK = 3;

    MakeMATRIKS(NB, NK, &M1);

    //Ngisi matriks manual;
    int i;
    int j;
    for (i=0; i< NB; i++){
        for (j=0; j<NK; j++){
            ElmtM(M1, i, j) = 'W';
        }
    }

    printf("\n");
    TulisMATRIKS(M1);
    printf("\n");

    if (IsIdxEff(M1, 1, 1)){
        printf("testing aja bro\n");
    }

    //Fungsi lain udah kepake di TulisMatriks, jadi kalau TulisMatriks udah benar
    // fungsi lain juga sudah pasti benar

    return 0;
}