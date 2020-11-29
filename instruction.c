
#include "instruction.h"


Instruction CreateInstruction(Kata command, POINT point, Kata detail, int qty, int map, int mcost, TabBahan bcost)
/* Membuat instruction baru dengan komponen seperti pada parameter dan mengembalikannya*/
{
	//KAMUS
	Instruction NewIns;

	//ALGORITMA
	Function(NewIns) = command;
	Point(NewIns) = point;
	Detail(NewIns) = detail;
	Quantity(NewIns) = qty;
	Map(NewIns) = map;
	MCost(NewIns) = mcost;
	BCost(NewIns) = bcost;

	return NewIns;
}