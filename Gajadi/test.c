#include <stdio.h>
#include <stdlib.h>

int PlayerTunnel(int MapIdPlayer, char Symbol)
/* Menghasilkan perpindahan player dari symbol yang dimasukkan */
{
    if ((MapIdPlayer == 1) && (Symbol = '>'))
    {
        return 2;
    }
    else if ((MapIdPlayer == 1) && (Symbol = 'v'))
    {
        return 3;
    }
    else if ((MapIdPlayer == 2) && (Symbol = '<'))
    {
        return 1;
    }
    else if ((MapIdPlayer == 2) && (Symbol = 'v'))
    {
        return 4;
    }
    else if ((MapIdPlayer == 3) && (Symbol = '>'))
    {
        return 4;
    }
    else if ((MapIdPlayer == 3) && (Symbol = '^'))
    {
        return 1;
    }
    else if ((MapIdPlayer == 4) && (Symbol = '<'))
    {
        return 3;
    }
    else if ((MapIdPlayer == 4) && (Symbol = '^'))
    {
        return 2;
    }
    else
    {
        return -1;
    }
}

int main()
{
    char sym;
    int x;

    scanf("%d", &x);
    scanf(" %c", &sym);
    // printf(" %c", sym);
    printf("%d", PlayerTunnel(x, sym));
    return 0;
}