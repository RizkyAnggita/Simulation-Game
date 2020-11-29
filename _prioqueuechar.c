#include <stdio.h>
#include <stdlib.h>
#include "prioqueuechar.h"
#include "pengunjung.h"

#define ENDL printf("\n")

int main()
{
	//KAMUS
	Pengunjung P1, P2, P3, P4, P5, PX;
	PrioQueueChar Q;

	//ALGORITMA
	Prio(P1) = 3;
	Prio(P2) = 5;
	Prio(P3) = 1;
	Prio(P4) = 4;
	Prio(P5) = 2;

	MakeEmptyPQ(&Q, 5);

	

	if (IsEmptyPQ(Q))
	{
		printf("Queue kosong\n");
	}

	PrintPrioQueueChar(Q);
	ENDL;

	Enqueue(&Q, P1);
	PrintPrioQueueChar(Q);
	ENDL;

	Enqueue(&Q, P2);
	PrintPrioQueueChar(Q);
	ENDL;

	Enqueue(&Q, P3);
	PrintPrioQueueChar(Q);
	ENDL;

	Enqueue(&Q, P4);
	PrintPrioQueueChar(Q);
	ENDL;

	Enqueue(&Q, P5);
	PrintPrioQueueChar(Q);
	ENDL;

	if (IsFullPQ(Q))
	{
		printf("Queue penuh\n");
	}

	Dequeue(&Q, &PX);
	PrintPrioQueueChar(Q);
	ENDL;
	printf("PX = %d\n", Prio(PX));
	printf("NB elmt = %d\n", NBElmtPQ(Q));



	return 0;
}