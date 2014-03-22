#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()														// for testing only
{   															// for testing only
	printf("How many columns and rows: ");						// for testing only
  	int d = GetInt();											// for testing only
  	int i = d;													
  	int j = d;													
  	int tile = (d * d) - 1;	
  	int top = (d * d) - 1;									
  	int board[i][j];
  	int onefortwo = 1;
  	int twoforone = 2;							
 	bool odd;
 	if (top % 2 == 1)
 	{
 		odd = true;
 	}
 	else
 	{
 		odd = false;
 	}
 		
	for (i = 0; i < d; i++)
	{
		for (j = 0; j < d; j++, tile--)
		{
			if (odd == true && tile == 2)
			{
				board[i][j] = onefortwo;
				printf("board[%i][%i] = %i\n", i, j, tile);			// for testing only
			}
			else if (odd == true && tile == 1)
			{
				board[i][j] = twoforone;
				printf("board[%i][%i] = %i\n", i, j, tile);			// for testing only
			}
			else
			{
				board[i][j] = tile;
				printf("board[%i][%i] = %i\n", i, j, tile); 		// for testing only
			}
		}
	}
	// possibly set the winning conditions here, by:
	// another for loop-for loop-count tiles back up, with special conditions if tile == 0  ??????
																
	int rows;
    int columns;
    tile = (d * d) -1;
    
    for (rows = 0; rows < d; rows++)
    {
    	printf("\n\n\n\n");
    	for (columns = 0; columns < d; columns++, tile--)
    	{
    		if (tile == 0)
    		{
    			printf("    __    ");
    		}
    		else
    		{
    			printf("    %2i    ", tile);
    		}
    	}
    }
    printf("\n\n\n\n");
}
