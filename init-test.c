#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{   
	printf("How many columns and rows: ");
  	int d = GetInt();
  	int top = (d - 1);	// top number, with 0-indexing
  	
  	int i = top;		// declared this in main()
  	int j = top;		// declared this in main()
  	int k = (d * d) -1;
  	
  	int board[i][j];		// declared this in main()
 	int spot[k];			// 
  	board[i][j] = spot[k];
	while (k > 0)
  	{
  		for (i = 0; i < d; i++)
			for (j = 0; j < d; j++, k--)
		
				printf("board[%i][%i] = spot[%i]\n", i, j, k);
	}
}
