#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{   
	printf("How many columns and rows: ");
  	int d = GetInt();
  
  	int i = d;		// declared this in main()
  	int j = d;		// declared this in main()
  	int k = (d * d) -1;
  	
  	int board[i][j];		// declared this in main()
 	int spot[k];			
  	board[i][j] = spot[k];
	while (k > 0)
  	{
  		for (i = 0; i < d; i++)
			for (j = 0; j < d; j++, k--)
			printf("board[%i][%i] = spot[%i]\n", i, j, k);
	}
}
