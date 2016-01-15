// init_playerをテストする

#include <curses.h>

#include "def.h"
#include "var.h"
#include "use_curses.h"
#include "init_player.h"

int main(void){
    init_curses();

    PLAYER_T player1;

    // windowの作成処理
    WINDOW *win;
    win = newwin(LINES,COLS-1,0,0);
    box(win,'|','-');

    // 作成した関数
    init_player(win, &player1);

    // windowの終了処理
    wclear(win);
    wrefresh(win);

    end_curses();

    return 0;
}
