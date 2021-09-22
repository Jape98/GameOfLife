#include "header.h"

/*********************************************************************
*    MAIN PROGRAM                                                      *
**********************************************************************/

int main(void)
{
  struct board matrix[GBOARD_MAX_WIDTH][GBOARD_MAX_HEIGHT] = {0, 0, 0};

  read_terrain(matrix);
  fill_population(matrix);

  init_ncurses();
  draw_borders(matrix);

  while(TRUE)
  {
  calculate_game(matrix); /*Calculates every index*/
  copy_matrix(matrix);    /*copies futre table to current table*/
  draw_matrix(matrix);    /*Draws both current tables*/

  usleep(500000);         /* 0,5s */
	refresh();              /* refreshes terminal */
  }
  close_ncurses();
}