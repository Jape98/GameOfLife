#include "header.h"

/********************************************************************/
/**
* 	FUNCTION DESCRIPTION
* --------------------------------------------------------------------
* NAME: Count
*
* DESCRIPTION: Counts amount of neighbours around the current index. Excluding borders. int population tells which counter is going to be used
*
* Input: struct board, int population
*
* Output: None
*
* Used global variables:
*   GBOARD_MAX_HEIGHT, GBOARD_MAX_WIDTH, BORDER, GRASS, MOUNTAIN, WATER, BUNKER, board
*/
/*********************************************************************/

int count_neighbours(struct board matrix[GBOARD_MAX_WIDTH][GBOARD_MAX_HEIGHT],int x, int y, int population)
{
  int neighbour = 0, xIndex=0, yIndex=0;

  xIndex = x;
  yIndex = y;

  
  if(population==1)
  {
    /*These 2 loops go around the current index and counts neighbours*/
    for (xIndex = x-1; xIndex <= x+1; xIndex++)
    {
      for (yIndex = y-1; yIndex <= y+1; yIndex++)
      {
        /*Checks if index is inside the borders*/
        if (xIndex < BORDER || yIndex < BORDER || xIndex >= GBOARD_MAX_WIDTH-BORDER || yIndex >= GBOARD_MAX_HEIGHT-BORDER)
        {
          /*If index is not on game table*/
          continue;
        }
        else
        {
          /*Adds value of current index to amount of neighbours*/
          neighbour = neighbour + matrix[xIndex][yIndex].current; 
        }   
      }
    }
  /*Reduce current index from neighbours because current cell cant be neighbour to itself*/
  neighbour = neighbour - matrix[x][y].current;
  }

  /*------------------------------------Population 2-------------------------------------------------*/
  else if(population==2)
  {
    /*These 2 loops go around the current index and counts neighbours*/
    for (xIndex = x-1; xIndex <= x+1; xIndex++)
    {
      for (yIndex = y-1; yIndex <= y+1; yIndex++)
      {
        /*Checks if index is inside the borders*/
        if (xIndex < BORDER || yIndex < BORDER || xIndex >= GBOARD_MAX_WIDTH-BORDER || yIndex >= GBOARD_MAX_HEIGHT-BORDER)
        {
          /*If index is not on game table*/
          continue;
        }
        else
        {
          /*Adds value of current index to amount of neighbours*/
          neighbour = neighbour + matrix[xIndex][yIndex].current2; 
        }   
      }
    }
  /*Reduce current index from neighbours because current cell cant be neighbour to itself*/
  neighbour = neighbour - matrix[x][y].current2;
  }



  return neighbour;
}