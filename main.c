
#include <stdio.h>
#include "mesinkata.h"
#include "utils.h"


#define ENDL printf("\n")

int main()
{

	Kata Command;

	Kata CNew;
	CNew.TabKata[0] = 'n';
	CNew.TabKata[1] = 'e';
	CNew.TabKata[2] = 'w';
	CNew.Length = 3;

	Kata CLoad;
	CLoad.TabKata[0] = 'l';
	CLoad.TabKata[1] = 'o';
	CLoad.TabKata[2] = 'a';
	CLoad.TabKata[3] = 'd';
	CLoad.Length = 4;

	Kata CExit;
	CExit.TabKata[0] = 'e';
	CExit.TabKata[1] = 'x';
	CExit.TabKata[2] = 'i';
	CExit.TabKata[3] = 't';
	CExit.Length = 4;

	Kata username;

	int day = 1;




	PrintTitle();
	ENDL;

	PrintMainMenu();
	ENDL;

	STARTKATA();

	if (IsKataSama(CKata, CNew))
	{
		printf("Memulai permainan baru...\n");

		printf("Masukkan nama:\n");
		STARTKATA();
		CopyKata(CKata, &username);

		printf("Preparation phase day %d\n", day);

		PrintMap();
		ENDL;
		ENDL;

		PrintPlayerStat(username);
		ENDL;

		PrintPrepStat();
		ENDL;

		ENDL;

		printf("Masukkan perintah:\n");


	} else if (IsKataSama(CKata, CLoad))
	{
		printf("load game\n");
	} else if (IsKataSama(CKata, CExit))
	{
		printf("exit");
	}






	// int i;

	// STARTKATA();
	// for (i = 0; i < CKata.Length; ++i)
	// {
	// 	printf("%c", CKata.TabKata[i]);
	// }

	// printf("\n");
}