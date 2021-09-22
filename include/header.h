/*-------------------------------------------------------------------*
*    HEADER FILES                                                    *
*--------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <time.h>
#include <ncurses.h>

/*-------------------------------------------------------------------*
*    GLOBAL VARIABLES AND CONSTANTS                                  *
*--------------------------------------------------------------------*/
/* Control flags */

/* Global constants */

#define BORDER 1
#define GBOARD_MAX_HEIGHT 50+(2*BORDER)
#define GBOARD_MAX_WIDTH 100+(2*BORDER)

#define BLACK_PAIR 1
#define GREEN_PAIR 2
#define WHITE_PAIR 3
#define BLUE_PAIR 4
#define YELLOW_PAIR 5
#define GREEN_PAIR2 6
#define WHITE_PAIR2 7
#define BLACK_PAIR2 8

#define GRASS 0
#define WATER 1
#define MOUNTAIN 2
#define BUNKER 3

/* Global structures */
struct board
{
  int current;
  int future;

  int current2;
  int future2;

  int terrain;
};

/*-------------------------------------------------------------------*
*    FUNCTION PROTOTYPES                                             *
*--------------------------------------------------------------------*/

void read_terrain(struct board matrix[GBOARD_MAX_WIDTH][GBOARD_MAX_HEIGHT]);    // Read map template from text file
void fill_population(struct board matrix[GBOARD_MAX_WIDTH][GBOARD_MAX_HEIGHT]); // Read population from text file

void draw_borders(struct board matrix[GBOARD_MAX_WIDTH][GBOARD_MAX_HEIGHT]); // Draw borders for the game
void draw_matrix(struct board matrix[GBOARD_MAX_WIDTH][GBOARD_MAX_HEIGHT]);  //prints alive cells on the screen

void calculate_game(struct board matrix[GBOARD_MAX_WIDTH][GBOARD_MAX_HEIGHT]);
int count_neighbours(struct board matrix[GBOARD_MAX_WIDTH][GBOARD_MAX_HEIGHT],int x, int y, int population);
void copy_matrix(struct board matrix[GBOARD_MAX_WIDTH][GBOARD_MAX_HEIGHT]);
void init_ncurses(void);
void close_ncurses(void);