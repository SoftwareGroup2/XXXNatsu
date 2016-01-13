// init_playerは前提としてcursesのinit,endが他関数で実行されるものと考える

#include <stdio.h>
#include <curses.h>

#include "def.h"
#include "var.h"
#include "use_curses.h"

int init_player(PLAYER_T *player);

int init_player(WINDOW *win, PLAYER_T *player){
    // とりあえずplayer構造体にプレイヤー名がないので適当に作っておく。
    char player_name[100];
    // memo: cursesの座標指定では、y,x の順で指定する
    nocbreak();               // bakc spaceによる文字の訂正ができる
    mvwaddstr(win, 1, 3, "プレイヤー名: ") getstr(player_name);

    return 0;
}

int main(void){
    init_curses(void);

    PLAYER_T player1;
    WINDOW *win;

    // ウィンドウがあると課程する。
    win = newwin(LINES,COLS-1,0,0);
    box(win,'|','-');

    init_player(win, player1);

    end_curses();

    return 0;
}
