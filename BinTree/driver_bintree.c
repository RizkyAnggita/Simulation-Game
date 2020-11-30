#include "bintree.h"

int main(){

    BinTree BT;
    TabBahan TB;
    Bahan B;
    Kata NamaWahana;

    int i;
    

    B.Name.TabKata[0] = 'W';
    B.Name.TabKata[1] = 'o';
    B.Name.TabKata[2] = 'o';
    B.Name.TabKata[3] = 'd';
    B.Name.Length = 4;
    B.Val = 10;

    for (i=0; i< 10; i++){
        Elmt(TB, i) = B;
    }
    

    NamaWahana.Length = 4;
    NamaWahana.TabKata[0] = 't';
    NamaWahana.TabKata[1] = 'e';
    NamaWahana.TabKata[2] = 's';
    NamaWahana.TabKata[3] = 't';

    WahanaGame WG = MakeWahanaGame(NamaWahana,5000, 1, 10, NamaWahana, 10000, TB);


    MakeTree(WG, NilBinTree, NilBinTree, &BT);

    if (!IsTreeEmpty(BT)){
        printf("Masuk\n");
        PrintTree(BT, 2); //Jika tercetak Wood 10 sebanyak 10 kali maka fungsi berjalan benar
    }


    return 0;
}