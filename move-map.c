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
- tile above	=	space[i - 1][j]
					"if !boardtop"
					
- tile below	=	space[i + 1][j]
					"if !boardbottom"
					
- tile to left 	=	space[i][j - 1]
					"if !boardleft"
					
- tile to right	=	space[i][j + 1]
					"if !boardright"
					
------------------------------------------------------------------------------
	if (mover == tile above && !boardtop) || 
		(mover == tile below && !boardbottom) || 
		(mover == tile left && !boardleft) ||
		(mover == tile right && !boardleft) 
					
-------------------------------------------------------------------------------

if [i] == (d - 1)
{
	boardbottom = true;
}

if [i] == (d - d)
{
	boardtop = true;
}

if [j] == (d - 1) 
{
	boardright = true;
}

if [j] == (d - d)
{
	boardleft = true;
}
					
					
*******************************************************************************
"*****************************************************************************"
*******************************************************************************

When the space(0) value moves (swaps values with another position 
on the board), explicitly declare 0 as the new value of that position.  
			
			 
			
			
			
			
			
			
			
