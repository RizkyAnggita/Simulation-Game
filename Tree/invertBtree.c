#include "bintree.h"
#include "listrek.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void InvertBtree(BinTree *P)
{
    if (!IsTreeEmpty(*P) && !IsTreeOneElmt(*P))
    {
        if (IsBiner(*P))
        {
            BinTree Q;

            InvertBtree(&(Left(*P)));
            InvertBtree(&(Right(*P)));
            Q = Left(*P);
            Left(*P) = Right(*P);
            Right(*P) = Q;
        }
        else if (IsUnerRight(*P))
        {
            InvertBtree(&(Left(*P)));
            InvertBtree(&(Right(*P)));
            Left(*P) = Right(*P);
            Right(*P) = Nil;
        }
        else if (IsUnerLeft(*P))
        {
            InvertBtree(&(Left(*P)));
            InvertBtree(&(Right(*P)));
            Right(*P) = Left(*P);
            Left(*P) = Nil;
        }
    }
}
/* I.S. Pohon P terdefinisi */
/* F.S. Pohon P diflip secara vertikal */
/*      Contoh:
           1
         2   5
        3 4 6
        Menjadi:
           1
         5   2
          6 4 3 */

/*  int main()
{
    int n;
    scanf("%d", &n);
    BinTree P = BuildBalanceTree(n);
    PrintPreorder(P);
    InvertBtree(&P);
    PrintTree(P, 2);
} */
