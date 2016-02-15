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

all: test-use_curses.out test-init_player.out test-init_players.out test-select_active_player.out test-throw_dice.out test-move_player.out test-game_end.out test-disp_game_window.out

test-use_curses.out : test-use_curses.c $(OBJ_DIR)/use_curses.o
	$(CC) $(INCLUDE) -o $@ $^ $(LCURSES)

test-init_player.out : test-init_player.c $(OBJ_DIR)/init_player.o $(OBJ_DIR)/use_curses.o $(OBJ_DIR)/init_calender.o $(OBJ_DIR)/program_init.o
	$(CC) $(INCLUDE) -o $@ $^ $(LCURSES)

test-init_players.out : test-init_players.c $(OBJ_DIR)/init_players.o $(OBJ_DIR)/init_player.o $(OBJ_DIR)/use_curses.o $(OBJ_DIR)/init_calender.o
	$(CC) $(INCLUDE) -o $@ $^ $(LCURSES)

test-select_active_player.out : test-select_active_player.c $(OBJ_DIR)/select_active_player.o
	$(CC) $(INCLUDE) -o $@ $^ $(LCURSES)

test-program_init.out : test-program_init.c $(OBJ_DIR)/program_init.o
	$(CC) $(INCLUDE) -o $@ $^ $(LCURSES)

test-init_calender.out : test-init_calender.c $(OBJ_DIR)/program_init.o $(OBJ_DIR)/init_calender.o
	$(CC) $(INCLUDE) -o $@ $^

test-move_player.out : test-move_player.c $(OBJ_DIR)/move_player.o $(OBJ_DIR)/init_calender.o $(OBJ_DIR)/program_init.o $(OBJ_DIR)/throw_dice.o
	$(CC) $(INCLUDE) -o $@ $^
test-throw_dice.out : test-throw_dice.c $(OBJ_DIR)/throw_dice.o
	$(CC) $(INCLUDE) -o $@ $^

test-disp_game_window.out : test-disp_game_window.c $(OBJ_DIR)/disp_game_window.o $(OBJ_DIR)/use_curses.o
	$(CC) $(INCLUDE) -o $@ $^ $(LCURSES)

test-game_end.out : test-game_end.c $(OBJ_DIR)/game_end.o $(OBJ_DIR)/use_curses.o
	$(CC) $(INCLUDE) -o $@ $^ $(LCURSES)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@[ -d $(OBJ_DIR) ]
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

clean:
	rm -f $(OBJ_DIR)/*.o *.out
