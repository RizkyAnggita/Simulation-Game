
#include "instruction.h"


Instruction CreateInstruction(Kata command, POINT point, Kata detail, int map)
/* Membuat instruction baru dengan komponen seperti pada parameter dan mengembalikannya*/
{
	//KAMUS
	Instruction NewIns;
	
	//ALGORITMA
	Function(NewIns) = command;
	Point(NewIns) = point;
	Detail(NewIns) = detail;
	Map(NewIns) = map;

	return NewIns;
}