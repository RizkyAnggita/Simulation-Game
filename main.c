
#include <stdio.h>

#include "mesinkata.h"
#include "point.h"
#include "jam.h"
#include "instruction.h"
#include "stackins.h"
#include "command.h"
#include "utils.h"
#include "constants.h"
#include "bintree.h"


#define ENDL printf("\n")


int main()
{

	// Initialize Game

	InitGameCommand();

	TabBahan ShopBahan = FileToListBahan(FILE_MATERIAL);

	MATRIKS Map1 = FileToMatriks(FILE_MAP_1);
	
	
	
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

	POINT PlayerPosition = MakePOINT(1, 1);

	int PlayerMap = 1;

	// Prep state

	StackI InstructionStack;
	CreateEmpty(&InstructionStack);

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

				PrintMap(PlayerMap, PlayerPosition, Map1);
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
					// TimeSpent = MakeJAM(0, 10, 0);
					// PrepTotalTime = NextNDetik(PrepTotalTime, JAMToDetik(TimeSpent));
					MovePlayer(Map1, 'w', &PlayerPosition);

				} else if (IsKataSama(CKata, CA))
				{
					MovePlayer(Map1, 'a', &PlayerPosition);

				} else if (IsKataSama(CKata, CS))
				{
					MovePlayer(Map1, 's', &PlayerPosition);

				} else if (IsKataSama(CKata, CD))
				{
					MovePlayer(Map1, 'd', &PlayerPosition);

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

					Bahan CBahan;
					STARTKATA(" ");
					Val(CBahan) = KataToInteger(CKata);
					ADVKATA(" ");
					Name(CBahan) = CKata;				

					int MoneyNeeded = PriceBuyBahan(Name(CBahan), Val(CBahan), ShopBahan);
					if (MoneyNeeded == -999) //Nama bahan tidak ditemukan
					{
						printf("Bahan yang ingin anda beli tidak tersedia\n");

					} else
					{
						Instruction NewInstruction = CreateInstruction(CBuy, PlayerPosition, Name(CBahan), Val(CBahan), PlayerMap);

						Push(&InstructionStack, NewInstruction);

						printf("You ");
						PrintKata(Function(InfoTop(InstructionStack)));
						printf(" %d ", Quantity(InfoTop(InstructionStack)));
						PrintKata(Detail(InfoTop(InstructionStack)));
						ENDL;

					}

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

				PrintMap(PlayerMap, PlayerPosition, Map1);
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