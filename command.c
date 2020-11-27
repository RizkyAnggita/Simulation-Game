
#include "command.h"

Kata CNew;
Kata CLoad;
Kata CExit;
Kata CW;
Kata CA;
Kata CS;
Kata CD;
Kata CBuild;
Kata CUpgrade;
Kata CBuy;
Kata CUndo;
Kata CExecute;
Kata CMain;
Kata CServe;
Kata CRepair;
Kata CDetail;
Kata COffice;
Kata CPrepare;

Kata MakeCommand(Kata * C, char * command, int length)
/* Membuat command dengan TabKata = command, dan Length = length*/
{
	//KAMUS
	int i;

	//ALGORITMA

	for (i = 0; i < length; ++i)
	{
		(*C).TabKata[i] = command[i];
	}

	(*C).Length = length;
}

void InitGameCommand()
/* I.S. Command game belum terdefinisi
   F.S Command game terdefinisi dan dapat digunakan dimanapun*/
{
	MakeCommand(&CNew, "new", 3);
	MakeCommand(&CLoad, "load", 4);
	MakeCommand(&CExit, "exit", 4);
	MakeCommand(&CW, "w", 1);
	MakeCommand(&CA, "a", 1);
	MakeCommand(&CS, "s", 1);
	MakeCommand(&CD, "d", 1);
	MakeCommand(&CBuild, "build", 5);
	MakeCommand(&CUpgrade, "upgrade", 7);
	MakeCommand(&CBuy, "buy", 3);
	MakeCommand(&CUndo, "undo", 4);
	MakeCommand(&CExecute, "execute", 7);
	MakeCommand(&CMain, "main", 4);
	MakeCommand(&CServe, "serve", 5);
	MakeCommand(&CRepair, "repair", 6);
	MakeCommand(&CDetail, "detail", 6);
	MakeCommand(&COffice, "office", 6);
	MakeCommand(&CPrepare, "prepare", 7);
}