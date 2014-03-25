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
*******************************************************************************
"*****************************************************************************"
			
"Possible Moves"
tile_above	=	space[i - 1][j]
					//valid "if !boardtop"
					
tile_below	=	space[i + 1][j]
					//valid "if !boardbottom"
					
tile_left 	=	space[i][j - 1]
					//valid "if !boardleft"
					
tile_right	=	space[i][j + 1]
					//valid "if !boardright"
-------------------------------------------------------------------
if space[i] == (d - 1)
{
	boardbottom = true;
}

if space[i] == (d - d)
{
	boardtop = true;
}

if space[j] == (d - 1) 
{
	boardright = true;
}

if space[j] == (d - d)
{
	boardleft = true;
}
				
------------------------------------------------------------------------------
	if ((!boardtop && (mover == tile_above)) || 
		(!boardbottom && (mover == tile_below)) || 
		(!boardleft && (mover == tile_left)) ||
		(!boardright && (mover == tile_right)))
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
			
			 
			
			
			
			
			
			
			
