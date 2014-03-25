/**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements the Game of Fifteen (generalized to d x d).
 *
 * Usage: ./fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [MIN,MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// board's minimal dimension
#define MIN 3

// board's maximal dimension
#define MAX 9

// board, whereby board[i][j] represents row i and column j
int board[MAX][MAX];

// Added in by TJ:
// winning board configuration, whereby win[i][j] represents row i and column j
int win[MAX][MAX];

// board's dimension
int d;  	

// variables added in by TJ:		
																
  	int space_i;
  	int space_j;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);
void save(void);

int main(int argc, string argv[])
{

  	
    // greet player
    greet();

    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: ./fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < MIN || d > MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            MIN, MIN, MAX, MAX);
        return 2;
    }

    // initialize the board
  	
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // saves the current state of the board (for testing)
        save();

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        //int tile = GetInt();		!!!!!!!!original code!!!!!!!!!
		int mover = GetInt();
		
        // move if possible, else report illegality
        // if (!move(tile))			!!!!!!!!!!original code!!!!!!!!!!
        if (!move(mover))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep for animation's sake
        usleep(500000);
    }

    // that's all folks
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1,
 * (i.e., fills board with values but does not actually print them),
 * whereby board[i][j] represents row i and column j.
 */
void init(void)
{
    // TODO
	int tile = (d * d) - 1;	
  	int top = (d * d) - 1;	
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
 		
	for (int i = 0; i < d; i++)
	{
		for (int j = 0; j < d; j++, tile--)
		{
			if (odd == true && tile == 2)
			{
				board[i][j] = onefortwo;
			//	printf("board[%d][%d] = %d\n", i, j, board[i][j]);	// for testing only
			}
			else if (odd == true && tile == 1)
			{
				board[i][j] = twoforone;
			//	printf("board[%d][%d] = %d\n", i, j, board[i][j]);	// for testing only
			}
			else
			{
				board[i][j] = tile;
			//	printf("board[%d][%d] = %d\n", i, j, board[i][j]); 		// for testing only
			}
		}
	}
	// create win values
	printf("\n");
	tile = 1;
	for (int i = 0; i < d; i++)
	{
		for (int j = 0; j < d; j++, tile++)
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
}
	// possibly set the winning conditions here, by:
	// another for loop-for loop-count tiles back up, with special conditions if tile == 0  ??????
										

/**
 * Prints the board in its current state.
 */
void draw(void)
{
	int space_i;
	int space_j;
    // TODO
    for (int i = 0; i < d; i++)
    {
    	printf("\n\n\n");
    	for (int j = 0; j < d; j++)
    	{
    		if (board[i][j] == 0)
    		{
    			space_i = i;
				space_j = j;
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


/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int mover)
{
    // TODO
    for (int i = 0; i < d; i++)
	{
		for (int j = 0; j < d; j++)
		{
			if (i == space_i && j == space_j)
			{
				bool boardtop;
				bool boardbottom;
				bool boardleft;
				bool boardright;
				int tile_above;
				int tile_below;
				int tile_right;
				int tile_left;
				if (space_i == (d - 1))
				{
					boardbottom = true;
				}
				else
				{
					boardbottom = false;
					tile_below = board[i + 1][j];
				}

				if (space_i == (d - d))
				{
					boardtop = true;
				}
				else
				{
					boardtop = false;
					tile_above = board[i - 1][j];
				}

				if (space_j == (d - 1))
				{
					boardright = true;
				}
				else
				{
					boardright = false;
					tile_right = board[i][j + 1];
				}

				if (space_j == (d - d))
				{
					boardleft = true;
				}
				else
				{
					boardleft = false;
					tile_left = board[i][j - 1];
				}
				
				if (!boardtop && (tile_above == mover))
				{
					board[i - 1][j] = 0;
					board[i][j] = tile_above;
					return true;
				}
				else if (!boardbottom && (tile_below  == mover))
				{
					board[i + 1][j] = 0;
					board[i][j] = tile_below;
					return true;
				}
				else if (!boardleft && (tile_left == mover))
				{
					board[i][j - 1] = 0;
					board[i][j] = tile_left;
					return true;
				}
				else if (!boardright && (tile_right == mover))
				{
					board[i][j + 1] = 0;
					board[i][j] = tile_right;
					return true;
				}
			}
		}
	}	
	return false;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    // TODO
    for (int i = 0; i < d; i++)
	{
		for (int j = 0; j < d; j++)
		{		
			if (board[i][j] == win[i][j])
			{
				return true;
			}
		}
	}
	return false;
}

/**
 * Saves the current state of the board to disk (for testing).
 */
void save(void)
{
    // log
    const string log = "log.txt";

    // delete existing log, if any, before first save
    static bool saved = false;
    if (!saved)
    {
        unlink(log);
        saved = true;
    }

    // open log
    FILE* p = fopen(log, "a");
    if (p == NULL)
    {
        return;
    }

    // log board
    fprintf(p, "{");
    for (int i = 0; i < d; i++)
    {
        fprintf(p, "{");
        for (int j = 0; j < d; j++)
        {
            fprintf(p, "%i", board[i][j]);
            if (j < d - 1)
            {
                fprintf(p, ",");
            }
        }
        fprintf(p, "}");
        if (i < d - 1)
        {
            fprintf(p, ",");
        }
    }
    fprintf(p, "}\n");

    // close log
    fclose(p);
}
