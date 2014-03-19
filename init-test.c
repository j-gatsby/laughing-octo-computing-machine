#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()														// for testing only
{   															// for testing only
	printf("How many columns and rows: ");						// for testing only
  	int d = GetInt();											// for testing only
  	int i = d;													// declare this in main()
  	int j = d;													// declare this in main()
  	int k = (d * d) -1;											// declare this in main()
  	int board[i][j];											// declare this in main()
 	int tile[k];												// declare this in main()
  	
  	board[i][j] = tile[k];
	while (k > 0)
  	{
  		for (i = 0; i < d; i++)
			for (j = 0; j < d; j++, k--)
			printf("board[%i][%i] = tile[%i]\n", i, j, k); 		// for testing only
	}
}																// for testing only
