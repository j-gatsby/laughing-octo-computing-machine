#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
		
int main()																		// for testing only
{   																			// for testing only
	printf("How many columns and rows: ");										// for testing only
  	int d = GetInt();															// for testing only
  	int i = d;													
  	int j = d;													
  	int tile = (d * d) - 1;	
  	int top = (d * d) - 1;									
  	int board[i][j];
  	int onefortwo = 1;
  	int twoforone = 2;							
 	bool odd;
 	int win[i][j];
 	printf(":::::::::::::::::::::::::::::::::::::::\n");
 	printf(":::::Starting Values for the Board:::::\n");
 	printf(":::::::::::::::::::::::::::::::::::::::\n");
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
				printf("board[%d][%d] = %d\n", i, j, board[i][j]);					// for testing only
			}
			else if (odd == true && tile == 1)
			{
				board[i][j] = twoforone;
				printf("board[%d][%d] = %d\n", i, j, board[i][j]);					// for testing only
			}
			else
			{
				board[i][j] = tile;
				printf("board[%d][%d] = %d\n", i, j, board[i][j]); 					// for testing only
			}
		}
	}
	printf(":::::::::::::::::::::::::::::::::::::::\n\n");
// create win values
	printf("\n");			
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("~~~Winning Values of the Board~~~\n");														// for testing only
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	tile = 1;
	for (i = 0; i < d; i++)
	{
		for (j = 0; j < d; j++, tile++)
		{					
			if (tile == d * d)
			{
				win[i][j] = 0;
				printf("win[%d][%d] = %d\n", i, j, win[i][j]);						// for testing only
			}
			else
			{
				win[i][j] = tile;
				printf("win[%d][%d] = %d\n", i, j, win[i][j]);						// for testing only
			}	
		}		
	}
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
// draw starting board  
	printf("----------------------------------\n");									// for testing only
	printf("|	Starting Configuration		|\n");									// for testing only
	printf("----------------------------------\n");									// for testing only
    for (i = 0; i < d; i++) 
    {
    	printf("\n\n\n");
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
    
    // draw winning board  															// for testing only
	printf("``````````````````````````````````\n");									// for testing only
	printf("`	Winning Configuration		`\n");									// for testing only
	printf("``````````````````````````````````\n");									// for testing only
    for (i = 0; i < d; i++)															// for testing only
    {																				// for testing only
    	printf("\n\n\n");															// for testing only
    	for (j = 0; j < d; j++)														// for testing only
    	{																			// for testing only
    		if (win[i][j] == 0)														// for testing only
    		{																		// for testing only
    			printf("   __   ");													// for testing only
    		}																		// for testing only
    		else																	// for testing only
    		{																		// for testing only
    			printf("   %2d   ", win[i][j]);										// for testing only
    		}																		// for testing only
    	}																			// for testing only
    }																				// for testing only
    printf("\n\n");	
    printf("'''''''''''''''''''''''''''''''\n");																// for testing only

// board[i][j] == win[i][j] ?????
	printf("******************************************\n");
	printf("*******Check for Winning Conditions*******\n");
	printf("******************************************\n");
	bool winner;

	for (i = 0; i < d; i++)
		{
			for (j = 0; j < d; j++)
			{		
				if (board[i][j] == win[i][j])
				{
					winner = true;
					printf("board[%d][%d] is %d, and win[%d][%d] is %d = !!!TRUE!!!\n", i, j, board[i][j], i, j, win[i][j]);
				}
				else
				{
					winner = false;
					printf("board[%d][%d] is %d, and win[%d][%d] is %d = FALSE\n", i, j, board[i][j], i, j, win[i][j]);
				}
			}
		}
	printf("********************************************\n");
}


