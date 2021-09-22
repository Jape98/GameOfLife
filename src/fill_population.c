#include "header.h"

/********************************************************************/
/**
* 	FUNCTION DESCRIPTION
* --------------------------------------------------------------------
* NAME: fill_population
*
* DESCRIPTION: Fills both current boards with 0 or 1
*
* Input: struct board
*
* Output: None
*
* Used global variables:
*   GBOARD_MAX_HEIGHT, GBOARD_MAX_WIDTH, BORDER, GRASS, MOUNTAIN, WATER, BUNKER, board
*/
/*********************************************************************/

void fill_population(struct board matrix[GBOARD_MAX_WIDTH][GBOARD_MAX_HEIGHT])
{
  srand(time(NULL));
	int x=0, y=0;

  for(y=BORDER;y<GBOARD_MAX_HEIGHT-BORDER;y++)
  {
    for(x=BORDER; x<GBOARD_MAX_WIDTH-BORDER; x++)
    {
      /*If terrain is something else than water*/
      if(matrix[x][y].terrain == !WATER) 
      {
      matrix[x][y].current=rand()%2;
      }
    }
  }
  /*Clears top right corner from any population 1 cells and randomly adds population 2 cells*/
  x=0, y=0;
  for(y= 0; y<25; y++)
  {
    for(x=65; x<GBOARD_MAX_WIDTH-BORDER; x++)
    {
      if(matrix[x][y].terrain == 2 || matrix[x][y].terrain == 0 || matrix[x][y].terrain == 3)
      {
      matrix[x][y].current2=rand()%2; /*population 2 = 0 or 1*/
      matrix[x][y].current=0;         /*population 1 = 0*/
      }
    }
  }
}