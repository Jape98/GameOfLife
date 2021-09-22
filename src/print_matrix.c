#include "header.h"

/********************************************************************/
/**
* 	FUNCTION DESCRIPTION
* --------------------------------------------------------------------
* NAME: print_matrix
*
* DESCRIPTION: Goes around terrain board and prints white, red or nothing
*
* Input: struct board
*
* Output: None
*
* Used global variables:
*   GBOARD_MAX_HEIGHT, GBOARD_MAX_WIDTH, BORDER, GRASS, MOUNTAIN, WATER, BUNKER, board
*/
/*********************************************************************/

void draw_matrix(struct board matrix[GBOARD_MAX_WIDTH][GBOARD_MAX_HEIGHT])
{
  int x=0, y=0;

  for(y=BORDER; y<GBOARD_MAX_HEIGHT-BORDER; y++)
  {
	  for(x=BORDER; x<GBOARD_MAX_WIDTH-BORDER; x++)
	  {

      /*---------------GRASS-------------------*/
      if(matrix[x][y].terrain == GRASS)
      {
        /*----Population1----*/
        if (matrix[x][y].current == 1)
        {
          attron(COLOR_PAIR(GREEN_PAIR));
          move(y,x);
          printw("O");
        }
        /*----Population2----*/
        else if (matrix[x][y].current2 == 1)
        {
          attron(COLOR_PAIR(GREEN_PAIR2));
          move(y,x);
          printw("O");
        }
        /*----Empty----*/
        else
        {
          attron(COLOR_PAIR(GREEN_PAIR));
          move(y,x);
          printw(" ");
        } 
      }
      
      /*---------------MOUNTAINS-------------*/
      else if(matrix[x][y].terrain == MOUNTAIN)
      {
        /*----Population1----*/
        if (matrix[x][y].current == 1)
        {
          attron(COLOR_PAIR(WHITE_PAIR));
          move(y,x);
          printw("O");
        }
        /*----Population2----*/
        else if (matrix[x][y].current2 == 1)
        {
          attron(COLOR_PAIR(WHITE_PAIR2));
          move(y,x);
          printw("O");
        }
        /*----Empty----*/
        else
        {
          attron(COLOR_PAIR(WHITE_PAIR));
          move(y,x);
          printw(" ");
        }
      }
      /*---------------BUNKER-------------*/
      else if(matrix[x][y].terrain == BUNKER)
      {
        /*----Population1----*/
        if (matrix[x][y].current == 1)
        {
          attron(COLOR_PAIR(BLACK_PAIR));
          move(y,x);
          printw("O");
        }
        /*----Population2----*/
        else if (matrix[x][y].current2 == 1)
        {
          attron(COLOR_PAIR(BLACK_PAIR2));
          move(y,x);
          printw("O");
        }
        /*----Empty----*/
        else
        {
          attron(COLOR_PAIR(BLACK_PAIR));
          move(y,x);
          printw(" ");
        }
      }

      /*----------------WATER-----------------*/
      if(matrix[x][y].terrain == WATER)
      {
        attron(COLOR_PAIR(BLUE_PAIR));
        move(y,x);
        printw("~");
      }
    }
  }
}
