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
  	int tile = (d * d) -1;										
  	int board[i][j];							
 											
	while (tile > 0)
  	{
  		for (i = 0; i < d; i++)
  		{
			for (j = 0; j < d; j++, tile--)
			{
				board[i][j] = tile;
				printf("board[%i][%i] = %i\n", i, j, tile); 		// for testing only
			}
		}
	}
																
	int rows;
    int columns;
    tile = (d * d) -1;
    
    for (rows = 0; rows < d; rows++)
    {
    	printf("\n\n\n\n");
    	for (columns = 0; columns < d; columns++, tile--)
    	{
    		printf("    %2i    ", tile);
    	}
    }
    printf("\n\n\n\n");
}
