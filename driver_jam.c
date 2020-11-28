/*
Nama    : Rizky Anggita S Siregar
NIM     : 13519132
Tanggal : 3 September 2020
Topik   : ADT Jam
Deskripsi: Driver ADT Jam, PraPraktikum 2
*/
#include <stdio.h>
#include "jam.h"

int main(){
    JAM J1, J2, J3;
    int h1,m1,s1;
    int h2,m2,s2;
    long detikJ1, dur;

    //BacaJAM
    printf("Masukkan HH:MM:SS J1: ");
    BacaJAM(&J1);
    printf("\n");
    printf("Masukkan HH:MM:SS J2: ");
    BacaJAM(&J2);

    //TulisJAM
    printf("\nJam yang dimasukkan J1: "); TulisJAM(J1);
    printf("\nJam yang dimasukkan J2: "); TulisJAM(J2);

    //JAMToDetik
    detikJ1 = JAMToDetik(J1);
    printf("\n\nJAMToDetik\nJ1 -> ");
    TulisJAM(J1);
    printf("\nDetik = %ld", detikJ1 );

    //DetikToJAM
    printf("\n\nDetikToJAM\nDetik = %ld", detikJ1);
    J3 = DetikToJAM(detikJ1);
    printf("\nJ3 adalah = "); TulisJAM(J3);

    //JEQ dan JNEQ
    printf("\n\nJEQ\n");
    if (JEQ(J1, J2)){
        printf("Jam J1 dan J2 sama\n");
    }
    else printf("Jam J1 dan J2 tidak sama\n");

    printf("\nJNEQ\n");
    if (JNEQ(J1, J2)){
        printf("Jam J1 dan J2 tidak sama\n");
    }
    else printf("Jam J1 dan J2 sama\n");

    //JLT dan JGT
    printf("\n\nJLT J1 dan J2\n");
    if (JLT(J1, J2)){
        printf("J1 kurang dari J2\n");
    }
    else printf("J1 lebih dari atau sama dengan J2");

    printf("\n\nJGT J1 dan J2\n");
    if (JGT(J1, J2)){
        printf("J1 lebih dari J2\n");
    }
    else printf("J1 kurang dari atau sama dengan J2");

    //NextDetik dan NextNDetik
    printf("\n\nNextDetik\n");
    printf("J3 -> Sebelum: "); TulisJAM(J3); printf("\n");
    J3 = NextDetik(J3);
    printf("NextDetik J3 -> Sesudah: "); TulisJAM(J3); printf("\n");

    printf("\nNextNDetik J3 , N=5\n");
    printf("J3 -> Sebelum: "); TulisJAM(J3); printf("\n");
    J3 = NextNDetik(J3, 5);
    printf("NextNDetik J3 -> Sesudah: "); TulisJAM(J3); printf("\n");

    //PrevDetik dan PrevNDetik
    printf("\n\nPrevDetik\n");
    printf("J3 -> Sebelum: "); TulisJAM(J3); printf("\n");
    J3 = PrevDetik(J3);
    printf("PrevDetik J3 -> Sesudah: "); TulisJAM(J3); printf("\n");

    printf("\nPrevNDetik J3 , N=5\n");
    printf("J3 -> Sebelum: "); TulisJAM(J3); printf("\n");
    J3 = PrevNDetik(J3, 5);
    printf("PrevNDetik J3 -> Sesudah: "); TulisJAM(J3); printf("\n");

    //Durasi
    printf("\nDurasi antara J1 dan J2");
    dur = Durasi(J1, J2);
    printf(" adalah %ld detik", dur);

    printf("\n-------------DONE-------------\n");
    return 0;
}