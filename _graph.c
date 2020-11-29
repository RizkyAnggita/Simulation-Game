#include <stdio.h>
#include "graph.h"

int main()
{
	int X  = 1;
	int X2 = 2;
	Graph G = CreateGraph(X);
	Graph G2;

	adrNode P1;

	if (SearchNode(G, X) != Nil)
	{
		printf("Node %d ditemukan di graph\n", X);
	} else
	{
		printf("Node %d tidak ditemukan di graph\n", X);
	}

	P1 = InsertNode(G, X2);

	if (SearchNode(G, X2) != Nil)
	{
		printf("Node %d ditemukan di graph\n", X2);
	} else
	{
		printf("Node %d tidak ditemukan di graph\n", X2);
	}

	G = InsertEdge(G, X, X2);

	if (SearchEdge(G, X, X2) != Nil)
	{
		printf("Edge dari node %d ke node %d ditemukan\n", X, X2);
	} else
	{
		printf("Edge dari node %d ke node %d ditemukan\n", X, X2);
	}


	return 0;
}