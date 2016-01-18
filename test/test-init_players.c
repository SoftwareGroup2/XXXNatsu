#include <curses.h>

#include "def.h"
#include "var.h"
#include "use_curses.h"
#include "init_player.h"
#include "init_players.h"

int main(){
    // プレイヤー数もどこかで定数としておいたほうがよさそう。
    int i;
    WINDOW *win;
    PLAYER_T players[4];


    init_curses();
    // 適当にwindowを作成
    win = newwin(LINES,COLS-1,0,0);
    box(win,'|','-');

    init_players(win, players);

    end_curses();

    print_players_status(players);

    return 0;
}
