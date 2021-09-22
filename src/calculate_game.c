#include "header.h"

/********************************************************************/
/**
* 	FUNCTION DESCRIPTION
* --------------------------------------------------------------------
* NAME: calculate_game
*
* DESCRIPTION: Calculates new value to every index
*
* Input: struct board
*
* Output: None
*
* Used global variables:
*   GBOARD_MAX_HEIGHT, GBOARD_MAX_WIDTH, BORDER, GRASS, MOUNTAIN, WATER, BUNKER, board
*/
/*********************************************************************/

void calculate_game(struct board matrix[GBOARD_MAX_WIDTH][GBOARD_MAX_HEIGHT])
{
  int neighbour=0, neighbour2=0;
  int x=0,y=0;
  int population = 0;

  /*2 Loops for going around every index excluding borders*/
  for (x=BORDER; x<GBOARD_MAX_WIDTH-BORDER; x++)
  {
    for (y=BORDER; y<GBOARD_MAX_HEIGHT-BORDER; y++) 
    {
      
      /**Population 1
      -----------------------------------------------------------------*/
        population=1;
        neighbour = count_neighbours(matrix, x, y, population);

      /*----------------------------Grass------------------------------*/
      /**
      * Population 1 grass rules:
      * 
      *  neighbours = action
      * 
      *         2 = do nothing
      *         3 = change value to 1 (new population)
      *         less than 2 = change value to 0 (Lonliness)
      *         more than 3 = change value to 0 (Overpopulation)
      */

      if(matrix[x][y].terrain == GRASS)
      {
        if (neighbour == 2)
        {
          matrix[x][y].future = matrix[x][y].current;
        }
        else if (neighbour == 3)
        {
          matrix[x][y].future = 1;
        }
        else
        {
          matrix[x][y].future = 0;
        }
      }
      /*---------------------------------------------------------------*/

      /*-------------------------Mountain------------------------------*/
      /**
      * Population 1 mountain rules:
      * 
      * neighbours = action
      * 
      *         less than 3 = do nothing
      *         3 or 4 = change value to 1 (new population)
      *         more than 4 = change value to 0 (Overpopulation)
      */
 
      else if(matrix[x][y].terrain == MOUNTAIN)
      {
        if (neighbour < 3)
        {
          matrix[x][y].future = matrix[x][y].current;
        }
        else if (neighbour == 3 || neighbour == 4)
        {
          matrix[x][y].future = 1;
        }
        else
        {
          matrix[x][y].future = 0;
        }
      }

      /*----------------------------------------------------------------*/ 

      /*-----------------------------Bunker-----------------------------*/
      /**
      * Population 1 bunker rules:
      * 
      * neighbours = action
      * 
      *         less than 1 = change value to 0 (Lonliness)
      *         1-2, more than 6 = do nothing
      *         from 3 to 5 = change value to 1 (new population)
      */
  
      else if(matrix[x][y].terrain == BUNKER)
      {
        if (neighbour == 1 || neighbour == 2  || neighbour >= 6 )
        {
          matrix[x][y].future = matrix[x][y].current;
        }
        else if (neighbour >= 3 && neighbour <=5)
        {
          matrix[x][y].future = 1;
        }
        else
        {
          matrix[x][y].future = 0;
        }
      }
      /*------------------------------------------------------------------*/

      /**Population 2
        ------------------------------------------------------------------*/
        population=2;
        neighbour2 = count_neighbours(matrix, x, y, population);
        
      /*-----------------------------Grass--------------------------------*/
      /**
      * Population 2 grass rules:
      * 
      * neighbours = action
      * 
      *         2 = do nothing
      *         3 = change value to 1 (new population)
      *         less than 2 = change value to 0 (Lonliness)
      *         more than 3 = change value to 0 (Overpopulation)
      */

      if(matrix[x][y].terrain == GRASS)
      {
        if (neighbour2 == 2)
        {
          matrix[x][y].future2 = matrix[x][y].current2;
        }
        else if (neighbour2 == 3)
        {
          matrix[x][y].future2 = 1;
        }
        else
        {
          matrix[x][y].future2 = 0;
        }
      }
      /*------------------------------------------------------------------*/

      /*----------------------------Mountain------------------------------*/
      /**
      * Population 2 mountain rules:
      * 
      * neighbours = action
      * 
      *         1 = do nothing
      *         2-4 = change value to 1 (new population)
      *         less than 1 = change value to 0 (Lonliness)
      *         more than 4 = change value to 0 (Overpopulation)
      */

      else if(matrix[x][y].terrain == MOUNTAIN)
      {
        if (neighbour2 == 1)
        {
          matrix[x][y].future2 = matrix[x][y].current2;
        }
        else if (neighbour2 >= 2 && neighbour2 < 5)
        {
          matrix[x][y].future2 = 1;
        }
        else if (neighbour2 >= 5)
        {
          matrix[x][y].future2 = 0;
        }
        else
        {
          matrix[x][y].future2 = 0;
        }
      }
      /*------------------------------------------------------------------*/

      /*-------------------------------Bunker-----------------------------*/
      /**
      * Population 2 bunker rules:
      * 
      * neighbours = action
      * 
      *         1 = do nothing
      *         more than 2 = change value to 1
      */

      else if(matrix[x][y].terrain == BUNKER)
      {
        if (neighbour2 <= 1)
        {
          matrix[x][y].future2 = matrix[x][y].current2;
        }
        else if (neighbour2 >= 2)
        {
          matrix[x][y].future2 = 1;
        }
      }
      /*-------------------------------------------------------------------*/

      /*------------------------------Water--------------------------------*/
      /**
      * If terrain isnt anything above, it must be water.
      * Water = 0 for both populations
      */
      /*-------------------------------------------------------------------*/

      else
      {
        matrix[x][y].future = 0;
        matrix[x][y].future2 = 0;
      }

      /** if both populations are 1 in same index, one with more neighbours wins */

      if( matrix[x][y].future == 1 && matrix[x][y].future2 == 1)
      {
        if( neighbour > neighbour2)
        {
          matrix[x][y].future = 1;
          matrix[x][y].future2 = 0;
        }
        else
        {
          matrix[x][y].future = 0;
          matrix[x][y].future2 = 1;
        }
        
      }
    }
  }
}