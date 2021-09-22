#include "header.h"

/********************************************************************/
/**
* 	FUNCTION DESCRIPTION
* --------------------------------------------------------------------
* NAME: draw_borders
*
* DESCRIPTION: Prints border color over whole matrix at the beginning before catual game loop
*
* Input: struct board
*
* Output: None
*
* Used global variables:
*   board, YELLOW_PAIR, GBOARD_MAX_WIDTH, GBOARD_MAX_HEIGHT
*/
/*********************************************************************/

void draw_borders(struct board matrix[GBOARD_MAX_WIDTH][GBOARD_MAX_HEIGHT])
{
  int x=0, y=0;

  for(y=0; y<GBOARD_MAX_HEIGHT; y++)
  {
	  for(x=0; x<GBOARD_MAX_WIDTH; x++)
	  {
        attron(COLOR_PAIR(YELLOW_PAIR));
        move(y,x);
        printw(" ");
    } 
  }
}
