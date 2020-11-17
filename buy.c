#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mesintoken.h"


int main(){

    FILE *material = fopen ("material.txt", "r");
    if(material==NULL){
        perror("File tidak bisa dibuka!\n");
        return 0;
    }
    char bahan[10][100];
    char line[100];
    int i, NLine;

    i = 0;
    NLine = 0;
    while(fgets(line, sizeof(line), material)){
        line[strcspn(line, "\n")] = 0;      //Removing "\n" from end of string
        strcpy(bahan[i], line);     //copy from bufer(line) into an array
        printf("%s\n", line);
        printf("Isi: %s\n", *(bahan+i));
        i++;
        NLine++;
    }
    fclose(material);

    // Menyimpan array besar ke array nama dan harga bahan
    char namaBahan[NLine/2][50];
    int hargaBahan[NLine/2];
    int a,b;
    a = 0;
    b = 0;

    int j;
    for ( j = 0; j < NLine; j++)
    {
        if (j%2==0){
            strcpy(namaBahan[a], bahan[j]);
            a++;
        }
        else{
            hargaBahan[b] = atoi(bahan[j]);
            b++;
        }
    }

    // Mencetak daftar bahan ke layar
    printf("Ingin membeli apa?\n");
    printf("List: \n");
    i = 0;
    for ( i = 0; i < NLine/2; i++)
    {
        printf("\t-  %s  %d\n", namaBahan[i], hargaBahan[i] );
    }

    // Terima inputan menggunakan Mesin Token (Mesin Kata modif)
    float moneyNeeded = 0;

    STARTTOKEN();
    while(!EndToken){
        printf("Banyaknya barang: %d\n", CToken.val);
        printf("Nama barang: %s\n", CToken.tkn);
        
        for (i=0; i< NLine/2; i++){
            if (strcmp(CToken.tkn, namaBahan[i])==0){
                moneyNeeded += (CToken.val * hargaBahan[i]);
            }
        }
        printf("Uang yang dibutuhkan: %.2f\n\n", moneyNeeded);

        // Cek jumlah uang yang dimiliki, jika cukup push ke stack dan kurangi uang yang dimiliki

        ADVTOKEN();
    }

    // Pengecekan jumlah uang, jika cukup push ke stack

    
    return 0;
}
