
#include "header.h"

/********************************************************************/
/**
* 	FUNCTION DESCRIPTION
* --------------------------------------------------------------------
* NAME: init_ncurses
*
* DESCRIPTION: Initializes terminal for ncurses, clears the terminal, sets color pairs and sets background color 
*
* Input: None
*
* Output: None
*
* Used global variables:
*   BLACK_PAIR, GREEN_PAIR, WHITE_PAIR, BLUE_PAIR, YELLOW_PAIR, 
*   GREEN_PAIR2, WHITE_PAIR2, BLACK_PAIR2
* 
*/
/*********************************************************************/

void init_ncurses(void)
{
  initscr();   //initialize screen
	clear();
	curs_set(0);  //invisible cursor

  start_color ();

	init_pair (BLACK_PAIR, COLOR_WHITE, COLOR_BLACK); /*Black, white text background*/
  init_pair (GREEN_PAIR, COLOR_BLACK, COLOR_GREEN); /*Green, black text, grass*/
  init_pair (WHITE_PAIR, COLOR_BLACK, COLOR_WHITE); /*White, black text mountain*/

  init_pair (BLUE_PAIR, COLOR_WHITE, COLOR_BLUE);      /*Blue, water*/

  init_pair (YELLOW_PAIR, COLOR_WHITE, COLOR_YELLOW);  /*Yellow, border*/

  init_pair (GREEN_PAIR2, COLOR_RED, COLOR_GREEN);  /*Green, red text*/
  init_pair (WHITE_PAIR2, COLOR_RED, COLOR_WHITE);  /*White, red text*/
  init_pair (BLACK_PAIR2, COLOR_RED, COLOR_BLACK);  /*Black, red text*/

	bkgd (COLOR_PAIR (BLACK_PAIR));
}