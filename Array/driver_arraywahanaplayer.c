#include "arraywahanaplayer.h"
#include <stdio.h>

int main(){

    WahanaPlayer A;
    Kata NamaWahana;
    TabBahan TB;
    Bahan B;
    POINT locW;
    int mapW;
    ListU H;
    int totalPlayW;
    int totalPlayDayW;
    int totalMoneyW;
    int totalMoneyDayW;
    boolean rusak;


    //Masukin bahan manual
    B.Name.TabKata[0] = 'W';
    B.Name.TabKata[1] = 'o';
    B.Name.TabKata[2] = 'o';
    B.Name.TabKata[3] = 'd';
    B.Name.Length = 4;
    B.Val = 10;

    Elmt(TB, 0) = B;

    NamaWahana.Length = 4;
    NamaWahana.TabKata[0] = 't';
    NamaWahana.TabKata[1] = 'e';
    NamaWahana.TabKata[2] = 's';
    NamaWahana.TabKata[3] = 't';

    // Type(StatW(A)) = NamaWahana;
    // Price(StatW(A)) = 5000; 
    // Capacity(StatW(A)) = 1;
    // DurationW(StatW(A)) = 10;
    // Description(StatW(A)) = NamaWahana; //Testing doang
    // MoneyCost(StatW(A)) = 10000; //UNtuk ngebuild;
    // BahanCost(StatW(A)) = TB;

    WahanaGame WG = MakeWahanaGame(NamaWahana,5000, 1, 10, NamaWahana, 10000, TB);
    locW = MakePOINT(3,5);
    CreateEmptyListU(&H);
    mapW = 1;
    totalPlayW = 2;
    totalPlayDayW = 3;
    totalMoneyW = 5;
    totalMoneyDayW = 7;
    rusak = false;
    
    A = MakeWahanaPlayer(WG, NamaWahana, locW, mapW, H, totalPlayW, totalPlayDayW, totalMoneyW, totalMoneyDayW, rusak);

    TabWahanaPlayer TWP;

    MakeEmptyListWP(&TWP);
    printf("NbElmtListWP Awal: %d\n", NbElmtListWP(TWP));
    ElmtWP(TWP,0) = A;

    printf("Test LocW.X: %d\n", Elmt(TWP,0).LocW.X);
    printf("Test LocW.Y: %d\n", Elmt(TWP,0).LocW.Y);
    printf("\n");

    printf("Nama wahana: ");
    PrintKata(Elmt(TWP,0).NamaW);
    printf("\n");
    if (!Elmt(TWP,0).BrokenW){
        printf("Tidak rusak!\n");
        printf("Harga wahana: %d\n", Elmt(TWP,0).StatW.Price);
        printf("Kapasitas wahana: %d\n", Elmt(TWP,0).StatW.Capacity);
    }
    
    printf("\n");
    printf("NbElmtListWP setelah: %d\n", NbElmtListWP(TWP));
    printf("Max NbElListWP: %d\n", MaxNbElListWP(TWP));
    printf("LastIdxListWP : %d\n", GetLastIdxListWP(TWP));
    printf("FirstIdxListWP: %d\n", GetFirstIdxListWP(TWP));

    return 0;
}