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
				printf("board[%d][%d] = %d\n", i, j, board[i][j]);	// for testing only
			}
			else if (odd == true && tile == 1)
			{
				board[i][j] = twoforone;
				printf("board[%d][%d] = %d\n", i, j, board[i][j]);	// for testing only
			}
			else
			{
				board[i][j] = tile;
				printf("board[%d][%d] = %d\n", i, j, board[i][j]); 		// for testing only
			}
		}
	}
	// possibly set the winning conditions here, by:
	// another for loop-for loop-count tiles back up, with special conditions if tile == 0  ??????
																
	//int rows;
    //int columns;
    //tile = (d * d) -1;
    
    //for (rows = 0; rows < d; rows++)
    for (i = 0; i < d; i++)
    {
    	printf("\n\n\n");
    	//for (columns = 0; columns < d; columns++, tile--)
    	for (j = 0; j < d; j++)
    	{
    		if (board[i][j] == 0)
    		{
    			printf("   __   ");
    		}
    		else
    		{
    			printf("   %2d   ", board[i][j]);
    		}
    	}
    }
    printf("\n\n\n\n");  
}
