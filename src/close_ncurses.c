#include "header.h"

/********************************************************************/
/**
* 	FUNCTION DESCRIPTION
* --------------------------------------------------------------------
* NAME: close_ncurses
*
* DESCRIPTION: Closes ncurses so terminal works after closing program.
*
* Input: None
*
* Output: None
*
* Used global variables: None
*   
*/
/*********************************************************************/

void close_ncurses(void)
{
  noecho ();
	getch();
  endwin();
}