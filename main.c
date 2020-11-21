
#include <stdio.h>

#include "mesinkata.h"
#include "mesinbahan.h"
#include "jam.h"
#include "utils.h"


#define ENDL printf("\n")


int main()
{

	// List of command

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

	Kata CW;
	CW.TabKata[0] = 'w';
	CW.Length = 1;

	Kata CA;
	CA.TabKata[0] = 'a';
	CA.Length = 1;

	Kata CS;
	CS.TabKata[0] = 's';
	CS.Length = 1;

	Kata CD;
	CD.TabKata[0] = 'd';
	CD.Length = 1;

	Kata CBuild;
	CBuild.TabKata[0] = 'b';
	CBuild.TabKata[1] = 'u';
	CBuild.TabKata[2] = 'i';
	CBuild.TabKata[3] = 'l';
	CBuild.TabKata[4] = 'd';
	CBuild.Length = 5;

	Kata CUpgrade;
	CUpgrade.TabKata[0] = 'u';
	CUpgrade.TabKata[1] = 'p';
	CUpgrade.TabKata[2] = 'g';
	CUpgrade.TabKata[3] = 'r';
	CUpgrade.TabKata[4] = 'a';
	CUpgrade.TabKata[5] = 'd';
	CUpgrade.TabKata[6] = 'e';
	CUpgrade.Length = 7;

	Kata CBuy;
	CBuy.TabKata[0] = 'b';
	CBuy.TabKata[1] = 'u';
	CBuy.TabKata[2] = 'y';
	CBuy.Length = 3;

	Kata CUndo;
	CUndo.TabKata[0] = 'u';
	CUndo.TabKata[1] = 'n';
	CUndo.TabKata[2] = 'd';
	CUndo.TabKata[3] = 'o';
	CUndo.Length = 4;

	Kata CExecute;
	CExecute.TabKata[0] = 'e';
	CExecute.TabKata[1] = 'x';
	CExecute.TabKata[2] = 'e';
	CExecute.TabKata[3] = 'c';
	CExecute.TabKata[4] = 'u';
	CExecute.TabKata[5] = 't';
	CExecute.TabKata[6] = 'e';
	CExecute.Length = 7;

	Kata CMain;
	CMain.TabKata[0] = 'm';
	CMain.TabKata[1] = 'a';
	CMain.TabKata[2] = 'i';
	CMain.TabKata[3] = 'n';
	CMain.Length = 4;

	Kata CServe;
	CServe.TabKata[0] = 's';
	CServe.TabKata[1] = 'e';
	CServe.TabKata[2] = 'r';
	CServe.TabKata[3] = 'v';
	CServe.TabKata[4] = 'e';
	CServe.Length = 5;

	Kata CRepair;
	CRepair.TabKata[0] = 'r';
	CRepair.TabKata[1] = 'e';
	CRepair.TabKata[2] = 'p';
	CRepair.TabKata[3] = 'a';
	CRepair.TabKata[4] = 'i';
	CRepair.TabKata[5] = 'r';
	CRepair.Length = 6;

	Kata CDetail;
	CRepair.TabKata[0] = 'd';
	CRepair.TabKata[1] = 'e';
	CRepair.TabKata[2] = 't';
	CRepair.TabKata[3] = 'a';
	CRepair.TabKata[4] = 'i';
	CRepair.TabKata[5] = 'l';
	CRepair.Length = 6;

	Kata COffice;
	COffice.TabKata[0] = 'o';
	COffice.TabKata[1] = 'f';
	COffice.TabKata[2] = 'f';
	COffice.TabKata[3] = 'i';
	COffice.TabKata[4] = 'c';
	COffice.TabKata[5] = 'e';
	COffice.Length = 6;

	Kata CPrepare;
	CPrepare.TabKata[0] = 'p';
	CPrepare.TabKata[1] = 'r';
	CPrepare.TabKata[2] = 'e';
	CPrepare.TabKata[3] = 'p';
	CPrepare.TabKata[4] = 'a';
	CPrepare.TabKata[5] = 'r';
	CPrepare.TabKata[6] = 'e';
	CPrepare.Length = 7;

	TabBahan ShopBahan = FileToListBahan();
	


    // Player state

	Kata Username;

	int Day = 1;

	boolean PrepPhase;

	boolean Play;

	JAM CurrentTime = MakeJAM(21, 0, 0);
	JAM TimeSpent = MakeJAM(0, 0, 0);

	JAM PrepStartTime = MakeJAM(21, 0, 0);
	JAM PrepEndTime = MakeJAM(9, 0, 0);
	JAM PrepTotalTime = MakeJAM(0, 0, 0);

	JAM MainStartTime = MakeJAM(9, 0, 0);
	JAM MainEndTime = MakeJAM(21, 0, 0);

	TabBahan BahanPlayer = CreateEmptyBahanPlayer(ShopBahan);



	// Main program 

	PrintTitle();
	ENDL;

	PrintMainMenu();
	ENDL;

	STARTKATA(" ");

	if (IsKataSama(CKata, CNew))
	{
		printf("Memulai permainan baru...\n");

		printf("Masukkan nama:\n");
		STARTKATA(" ");
		CopyKata(CKata, &Username);

		Play = true;

		PrepPhase = true;

		while (Play)
		{

			if (PrepPhase)
			{
				printf("Preparation phase day %d\n", Day);

				PrintMap();
				ENDL;
				ENDL;

				PrintPlayerStat(Username);
				ENDL;

				PrintTime(CurrentTime, PrepEndTime, true);
				ENDL;

				PrintPrepStat(PrepTotalTime);
				ENDL;
				ENDL;

				printf("Masukkan perintah:\n");

				STARTKATA(" ");

				if (IsKataSama(CKata, CW))
				{
					TimeSpent = MakeJAM(0, 10, 0);
					PrepTotalTime = NextNDetik(PrepTotalTime, JAMToDetik(TimeSpent));
					printf("Wwwwwwwwwwwwwwwwwwwwwwwwwwwwwww\n");

				} else if (IsKataSama(CKata, CA))
				{
					printf("Aaaaaaaaaaaaaaaaaaaaaaaaaaaaa\n");

				} else if (IsKataSama(CKata, CS))
				{
					printf("S\n");

				} else if (IsKataSama(CKata, CD))
				{
					printf("D\n");

				} else if (IsKataSama(CKata, CBuild))
				{
					printf("Build\n");

				} else if (IsKataSama(CKata, CUpgrade))
				{
					printf("upgr\n");

				} else if (IsKataSama(CKata, CBuy))
				{
					PrintBahanPlayer(BahanPlayer);
					ENDL;

					PrintBuyBahan(ShopBahan);
					ENDL;

					STARTBAHAN(" ");
					printf("You are buying %d ", CBahan.Val);
					PrintKata(CBahan.Name);
					ENDL;

				} else if (IsKataSama(CKata, CUndo))
				{
					printf("undo\n");

				} else if (IsKataSama(CKata, CExecute))
				{
					PrepPhase = false;
					printf("exec\n");

				} else if (IsKataSama(CKata, CMain))
				{
					PrepPhase = false;
					printf("Main\n");

				} else if (IsKataSama(CKata, CExit))
				{
					Play = false;

				}

			} else // Main Phase
			{

				printf("Main phase day %d\n", Day);

				PrintMap();
				ENDL;
				ENDL;

				PrintPlayerStat(Username);
				ENDL;

				PrintTime(CurrentTime, MainEndTime, false);
				ENDL;

				PrintMainQueue();
				ENDL;
				ENDL;

				printf("Masukkan perintah:\n");

				STARTKATA(" ");

				if (IsKataSama(CKata, CServe))
				{
					printf("serve\n");

				} else if (IsKataSama(CKata, CRepair))
				{
					printf("repair\n");

				} else if (IsKataSama(CKata, CDetail))
				{
					printf("Detail\n");

				} else if (IsKataSama(CKata, COffice))
				{
					printf("Office\n");

				} else if (IsKataSama(CKata, CPrepare))
				{
					PrepPhase = true;
					Day += 1;
					printf("Prepare\n");
				
				} else if (IsKataSama(CKata, CExit))
				{
					Play = false;

				}				
			}

			 
		}	


	} else if (IsKataSama(CKata, CLoad))
	{
		printf("load game\n");
	} else if (IsKataSama(CKata, CExit))
	{
		printf("exit\n");
	}






	// int i;

	// STARTKATA();
	// for (i = 0; i < CKata.Length; ++i)
	// {
	// 	printf("%c", CKata.TabKata[i]);
	// }

	// printf("\n");
}