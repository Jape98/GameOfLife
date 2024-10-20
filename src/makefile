IDIR =../include
CC=gcc
CFLAGS=-I $(IDIR) #-Wall -pedantic -Wextra

ODIR=obj
LDIR=../lib
SDIR=src

LIBS=

_DEPS = header.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS)) 

_OBJ = calculate_game.o close_ncurses.o copy_matrix.o count_neighbours.o draw_borders.o fill_population.o init_ncurses.o main.o print_matrix.o read_terrain.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

gameoflife: $(OBJ)
	$(CC) -o $@ $^ $(LIBS) -lncurses

$(ODIR)/%.o: %.c $(DEPS) 
	$(CC) -c -o $@ $< $(CFLAGS)


	
.PHONY: clean
					
clean:
	rm -f $(ODIR)/*.o