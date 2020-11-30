#include "point.h"
#include <stdio.h>

int main(){
    POINT P,P2,P3;
    
    P = MakePOINT(2,3);
    printf("P.X: %d\n",Absis(P));
    printf("P.Y: %d\n",Ordinat(P));
    printf("\n");


    P2 = MakePOINT(2,3);
    printf("P2.X: %d\n",Absis(P2));
    printf("P2.Y: %d\n",Ordinat(P2));
    printf("\n");

    if(EQ(P,P2)){
        printf("Titik sama\n");
    }
    if (NEQ(P,P2)){
        printf("Titik tidak sama\n");
    }
    printf("\n");

    P3 = NextX(P);
    printf("NextX P: \n");
    printf("P3.X: %d\n",Absis(P3));
    printf("P3.Y: %d\n",Ordinat(P3));
    printf("\n");

   P3 = NextY(P);
    printf("NextY P: \n");
    printf("P3.X: %d\n",Absis(P3));
    printf("P3.Y: %d\n",Ordinat(P3));
    printf("\n");

    P3 = PrevX(P);
    printf("PrevX P: \n");
    printf("P3.X: %d\n",Absis(P3));
    printf("P3.Y: %d\n",Ordinat(P3));
    printf("\n");

    P3 = PrevY(P);
    printf("PrevY P: \n");
    printf("P3.X: %d\n",Absis(P3));
    printf("P3.Y: %d\n",Ordinat(P3));
    printf("\n");

    P3 = PlusDelta(P, 5,5);
    printf("PlusDelta P: \n");
    printf("P3.X: %d\n",Absis(P3));
    printf("P3.Y: %d\n",Ordinat(P3));
    printf("\n");

    return 0;
}