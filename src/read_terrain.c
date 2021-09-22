#include "header.h"

/********************************************************************/
/**
* 	FUNCTION DESCRIPTION
* --------------------------------------------------------------------
* NAME: read_terrain
*
* DESCRIPTION: Reads terrain from .txt and save it to terrain board.
*
* Input: struct board, template_europe.txt
*
* Output: None
*
* Used global variables:
*   GBOARD_MAX_HEIGHT, GBOARD_MAX_WIDTH, BORDER
*/
/*********************************************************************/

void read_terrain(struct board matrix[GBOARD_MAX_WIDTH][GBOARD_MAX_HEIGHT])
{
	int x=0, y=0;

  /*filepointer = fp*/
	FILE *fp; 

  /*open file for reading*/
  fp = fopen("template_europe.txt", "r"); 

  /*Goes around every index excluding borders*/
    for(y=BORDER;y<GBOARD_MAX_HEIGHT-BORDER;y++)
    {
      for(x=BORDER; x<GBOARD_MAX_WIDTH-BORDER; x++)
      {
        fscanf(fp,"%d", &matrix[x][y].terrain);
      }
    }

  fclose(fp);
}