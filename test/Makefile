# $B$3$N(BMakefile$B$r8+$?$i$I$N%W%m%0%i%`$r<B9T$9$k$N$K$I$N%U%!%$%k$,I,MW$J$N$+$o$+$k$h$&$K!#(B

# $B>C$9$N$,3Z$@$+$i<B9T%U%!%$%k$O(B.out$B$r$D$1$k(B

.SUFFIXES:
.SUFFIXES: .o .c

CC		= gcc
CFLAGS	= -Wall -O2
LCURSES	= -lncurses

OBJ_DIR= ../obj
SRC_DIR= ../game

INCLUDE=-I../game/

all: test-use_curses.out test-init_player.out test-init_players.out

test-use_curses.out : test-use_curses.c $(OBJ_DIR)/use_curses.o
	$(CC) $(INCLUDE) -o $@ $^ $(LCURSES)

test-init_player.out : test-init_player.c $(OBJ_DIR)/init_player.o $(OBJ_DIR)/use_curses.o
	$(CC) $(INCLUDE) -o $@ $^ $(LCURSES)

test-init_players.out : test-init_players.c $(OBJ_DIR)/init_players.o $(OBJ_DIR)/init_player.o $(OBJ_DIR)/use_curses.o
	$(CC) $(INCLUDE) -o $@ $^ $(LCURSES)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@[ -d $(OBJ_DIR) ]
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

clean:
	rm -f $(OBJ_DIR)/*.o *.out