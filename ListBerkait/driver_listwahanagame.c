#include "listwahanagame.h"
#include <stdio.h>

int main(){
    ListWG LWG;
    TabBahan TB;
    Bahan B;
    Kata NamaWahana;
    CreateEmptyListWG(&LWG);

    if (IsEmptyListWG(LWG)){
        printf("ListWG Kosong\n");
    }

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

    WahanaGame WG = MakeWahanaGame(NamaWahana,5000, 1, 10, NamaWahana, 10000, TB);

    BinTree BT = Tree(WG, NilBinTree, NilBinTree);
    PrintTree(BT, 2);

    InsVFirstListWG(&LWG, BT);

    Bahan B2;
    TabBahan TB1;
    B2.Name.TabKata[0] = 'W';
    B2.Name.TabKata[1] = 'o';
    B2.Name.TabKata[2] = 'o';
    B2.Name.TabKata[3] = 'd';
    B2.Name.Length = 4;
    B2.Val = 15;

    Elmt(TB1, 0) = B2;

    Kata NamaWahana2;
    NamaWahana2.Length = 4;
    NamaWahana2.TabKata[0] = 't';
    NamaWahana2.TabKata[1] = 'e';
    NamaWahana2.TabKata[2] = 's';
    NamaWahana2.TabKata[3] = 't';

    WahanaGame WG2 = MakeWahanaGame(NamaWahana2,10000, 2, 10, NamaWahana2, 5500, TB1);

    BinTree BT2 = Tree(WG2, NilBinTree, NilBinTree);
    PrintTree(BT2, 2);
    InsVFirstListWG(&LWG, BT2);

    addressListWG P2 = FirstListWG(LWG);

    if(!IsEmptyListWG(LWG)){
        //Kalau sudah kecetak, berarti sudah masuk ListWG, DONE
        while (P2 != NilListWG){
            printf("\n\n");
            int akapasitas = InfoListWG(P2)->info.Capacity;
            Kata aNamaW = InfoListWG(P2)->info.Type;
            int aharga = InfoListWG(P2)->info.Price;
            printf("Kapasitas: %d\n", akapasitas);
            printf("Harga    : %d\n", aharga);
            printf("Nama wahana: "); PrintKata(aNamaW); printf("\n");
            P2 = NextListWG(P2);
        }
        
    }

    return 0;
}