space[i][j]
	- if [i] == (d - 1) --> bottom row
		// space[i - 1][j]
			- tile above
		// space[i][j - 1]
			- tile to left
		// space[i][j + 1]
			- tile to right
		
				- && [j] == (d - 1) --> bottom right corner
					// space[i - 1][j]
						- tile above
					// space[i][j - 1]
						- tile to left
				
				- && [j] == (d - d) --> bottom left corner
					// space[i - 1][j]
						- tile above
					// space[i][j + 1]
						- tile to right
	
	
	- if [i] == (d - d) --> top row
		// space[i + 1][j]
			- tile below
		// space[i][j - 1]
			- tile to left
		// space[i][j + 1]
			- tile to right
		
				- && [j] == (d - 1) --> top right corner
					// space[i + 1][j]
						- tile below
					// space[i][j - 1]
						- tile to left
				
				- && [j] == (d - d) --> top left corner
					// space[i + 1][j]
						- tile below
					// space[i][j + 1]
						- tile to right
				
	- if [j] == (d - 1) --> right column
		// space[i][j - 1]
			- tile to left
		// space[i - 1][j]
			- tile above
		// space[i + 1][j]
			- tile below
		
	- if [j] == (d - d) --> left column
		// space[i][j + 1]
			- tile to right
		// space[i - 1][j]
			- tile above
		// space[i + 1][j]
			- tile below
			
			
	- else --> middle of board
		// space[i - 1][j]
			- tile above
		// space[i + 1][j]
			- tile below
		// space[i][j - 1]
			- tile to left
		// space[i][j + 1]
			- tile to right

"*****************************************************************************"		
"Possible Moves"
int tile_above	=	board[i - 1][j]
					//valid "if !boardtop"
					
int tile_below	=	board[i + 1][j]
					//valid "if !boardbottom"
					
int tile_left 	=	board[i][j - 1]
					//valid "if !boardleft"
					
int tile_right	=	board[i][j + 1]
					//valid "if !boardright"	
*******************************************************************************
"*****************************************************************************"
-------------------------------------------------------------------------------

when giving 0 the symbol "_" save the following:
space_i = i;
space_j = j;
-------------------------------------------------------------------------------

int space_i;
int space_j;
bool boardtop;
bool boardbottom;
bool boardleft;
bool boardright;
int tile_above;
int tile_below;
int tile_right;
int tile_left;
			
-------------------------------------------------------------------
if space_i == (d - 1)
{
	boardbottom = true;
}
else
{
	boardbottom = false;
	tile_below = board[i + 1][j];
}


if space_i == (d - d)
{
	boardtop = true;
}
else
{
	boardtop = false;
	tile_above = board[i - 1][j];
}


if space_j == (d - 1) 
{
	boardright = true;
}
else
{
	boardright = false;
	tile_right = board[i][j + 1];
}


if space_j == (d - d)
{
	boardleft = true;
}
else
{
	boardleft = false;
	tile_left = board[i][j - 1];
}
				
-------------------------------------------------------------------------------

------------------------------------------------------------------------------
	if ((!boardtop && (tile_above == mover)) || 
		(!boardbottom && (tile_below  == mover)) || 
		(!boardleft && (tile_left == mover)) ||
		(!boardright && (tile_right == mover)))
		{
			"swap mover with space"
		}
	else
	{
		return "move not valid"
	}
			
					
*******************************************************************************
"*****************************************************************************"
*******************************************************************************

When the space(0) value moves (swaps values with another position 
on the board), explicitly declare 0 as the new value of that position.  
			
			 
			
			
			
			
			
			
			
