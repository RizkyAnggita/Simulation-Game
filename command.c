
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


void InitGameCommand()
/* I.S. Command game belum terdefinisi
   F.S Command game terdefinisi dan dapat digunakan dimanapun*/
{
	MakeKata(&CNew, "new", 3);
	MakeKata(&CLoad, "load", 4);
	MakeKata(&CExit, "exit", 4);
	MakeKata(&CW, "w", 1);
	MakeKata(&CA, "a", 1);
	MakeKata(&CS, "s", 1);
	MakeKata(&CD, "d", 1);
	MakeKata(&CBuild, "build", 5);
	MakeKata(&CUpgrade, "upgrade", 7);
	MakeKata(&CBuy, "buy", 3);
	MakeKata(&CUndo, "undo", 4);
	MakeKata(&CExecute, "execute", 7);
	MakeKata(&CMain, "main", 4);
	MakeKata(&CServe, "serve", 5);
	MakeKata(&CRepair, "repair", 6);
	MakeKata(&CDetail, "detail", 6);
	MakeKata(&COffice, "office", 6);
	MakeKata(&CPrepare, "prepare", 7);
}