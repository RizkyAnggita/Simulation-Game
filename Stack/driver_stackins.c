
#include <stdio.h>
#include "../ADTLain/point.h"
#include "../ADTLain/instruction.h"
#include "stackins.h"

void PrintInstruction(Instruction I);

void PrintStackIns(StackI S);

int main(){
	Kata F, D;
	POINT P;
	Instruction I;
	StackI S;

	CreateEmpty(&S);
	PrintStackIns(S);

	if (IsEmpty(S)) {
		printf("\nThis stack is empty\n\n");
	}

	F.TabKata[0] = 'b';
	F.TabKata[1] = 'u';
	F.TabKata[2] = 'i';
	F.TabKata[3] = 'l';
	F.TabKata[4] = 'd';
	F.Length = 5;

	P = MakePOINT(5, 5);

	D.TabKata[0] = 't';
	D.TabKata[1] = 'e';
	D.TabKata[2] = 'm';
	D.TabKata[3] = 'p';
	D.Length = 4;

	I = CreateInstruction(F, P, D, 1, 3);

	printf("First instruction:\n");
	PrintInstruction(I);
	printf("Pushing:\n\n");

	Push(&S, I);
	PrintStackIns(S);
	printf("\n");

	F.TabKata[0] = 'b';
	F.TabKata[1] = 'u';
	F.TabKata[2] = 'y';
	F.Length = 3;

	P = MakePOINT(-1, -1);

	D.TabKata[0] = 'w';
	D.TabKata[1] = 'o';
	D.TabKata[2] = 'o';
	D.TabKata[3] = 'd';
	D.Length = 4;

	I = CreateInstruction(F, P, D, 10, 2);

	printf("Second instruction:\n");
	PrintInstruction(I);
	printf("Pushing:\n\n");

	Push(&S, I);
	PrintStackIns(S);
	printf("\n");

	while (!(IsFull(S))) {
		Push(&S, I);
	}

	PrintStackIns(S);

	if (IsFull(S)) {
		printf("This stack is full\n\nUndo: \n\n");
	}

	Undo(&S);

	F.TabKata[0] = 'u';
	F.TabKata[1] = 'p';
	F.TabKata[2] = 'g';
	F.TabKata[3] = 'r';
	F.TabKata[4] = 'a';
	F.TabKata[5] = 'd';
	F.TabKata[6] = 'e';
	F.Length = 7;

	P = MakePOINT(5, 5);

	D.TabKata[0] = 't';
	D.TabKata[1] = 'e';
	D.TabKata[2] = 'm';
	D.TabKata[3] = 'p';
	D.Length = 4;

	I = CreateInstruction(F, P, D, 1, 3);

	printf("Last instruction:\n");
	PrintInstruction(I);
	printf("Pushing:\n\n");

	Push(&S, I);
	PrintStackIns(S);

	printf("\n\nand Popping:\n\n");
	Pop(&S, &I);
	PrintStackIns(S);
	printf("\nPopped Instruction:\n");
	PrintInstruction(I);

	printf("\n\nand Popping:\n\n");
	Pop(&S, &I);
	PrintStackIns(S);
	printf("\nPopped Instruction:\n");
	PrintInstruction(I);

	printf("\n\nand Popping:\n\n");
	Pop(&S, &I);
	PrintStackIns(S);
	printf("\nPopped Instruction:\n");
	PrintInstruction(I);

	return 0;
}

void PrintInstruction(Instruction I){
	Kata F, D;
	POINT P;
	int Q, M;

	F = Function(I);
	P = Point(I);
	D = Detail(I);
	Q = Quantity(I);
	M = Map(I);

	printf("<");

	for (int i = 0; i < F.Length; i++) {
		printf("%c", F.TabKata[i]);
	}

	printf(", (%d,%d), ", Absis(P), Ordinat(P));

	for (int j = 0; j < D.Length; j++) {
		printf("%c", D.TabKata[j]);
	}

	printf(", %d, %d>\n", Q, M);
}

void PrintStackIns(StackI S){
	Instruction I;

	if (IsEmpty(S)) {
		printf("[]");
	} else {
		while (!(IsEmpty(S))) {
			I = InfoTop(S);
			PrintInstruction(I);
			Top(S)--;
		}
	}
}