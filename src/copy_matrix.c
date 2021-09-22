#include "header.h"

/********************************************************************/
/**
* 	FUNCTION DESCRIPTION
* --------------------------------------------------------------------
* NAME: Copy Matrix
*
* DESCRIPTION: Sets future board as current board, so new populations can be calculated to future boards again.
*
* Input: struct board
*
* Output: None
*
* Used global variables: struct board
*   
*/
/*********************************************************************/

void copy_matrix(struct board matrix[GBOARD_MAX_WIDTH][GBOARD_MAX_HEIGHT])
{
  int x=0, y=0;

  for (x = BORDER; x < GBOARD_MAX_WIDTH-BORDER; x++)
  {
    for (y = BORDER; y < GBOARD_MAX_HEIGHT-BORDER; y++)
    {
      matrix[x][y].current = matrix[x][y].future;
      matrix[x][y].current2 = matrix[x][y].future2;
    }
  }
}