# このMakefileを見たらどのプログラムを実行するのにどのファイルが必要なのかわかるように。

# 消すのが楽だから実行ファイルは.outをつける

.SUFFIXES:
.SUFFIXES: .o .c

CC		= gcc
CFLAGS	= -Wall -O2
LCURSES	= -lncurses

OBJ_DIR= ../obj
SRC_DIR= ../game

INCLUDE=-I../game/

all: game_main.out

game_main.out : main.c $(OBJ_DIR)/program_init.o $(OBJ_DIR)/init_player.o $(OBJ_DIR)/init_players.o $(OBJ_DIR)/init_calender.o $(OBJ_DIR)/throw_dice.o $(OBJ_DIR)/use_curses.o $(OBJ_DIR)/select_active_player.o
	$(CC) $(INCLUDE) -o $@ $^ $(LCURSES)
	cp game_main.out ../bin/game_main.out

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@[ -d $(OBJ_DIR) ]
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

clean:
	rm -f $(OBJ_DIR)/*.o *.out
