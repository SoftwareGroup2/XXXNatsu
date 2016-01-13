CC=gcc
LCURSES=-lncurses

ALL=init_player

USE_FILE=use_curses.o init_player.o

all: ${ALL}

init_player: ${USE_FILE}
	${CC} -o $@ $^ ${LCURSES}

.c.o:
	${CC} -c $<
