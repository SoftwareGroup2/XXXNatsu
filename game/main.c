// ゲーム本体のプログラム

#include <curses.h>
#include <stdlib.h>

#include "def.h"
#include "var.h"

#include "program_init.h"
#include "init_player.h"
#include "init_players.h"
#include "init_calender.h"
#include "move_player.h"
#include "throw_dice.h"
#include "use_curses.h"
#include "select_active_player.h"
#include "game_end.h"

void game_main(WINDOW *main_win, TROUT_T base_cal[CALENDER_KIND][CALENDER_LEN+1], PLAYER_T players[4]){
    int i,j;
    int move_player_id;

    // 最後のプレイヤーがゴールするまでループ
    move_player_id = select_active_player(players);
    while(players[move_player_id].day <= 44){
        move_player(&players[move_player_id]);
        move_player_id = select_active_player(players);
    }
}

int main(int argc, const char *argv[])
{
    WINDOW *main_win;
    TROUT_T base_cal[CALENDER_KIND][CALENDER_LEN+1];
    PLAYER_T players[4];

    // プログラムの初期化(カレンダーの初期化)
    if(program_init(base_cal) == FALSE){
        // 異常終了でプログラム終了
        exit(-1);
    }

    // cursesの初期化
    init_curses();
    // 画面サイズのメインウインドウを生成
    main_win = newwin(35,100,0,0);
    box(main_win,'|','-');

    // プレイヤーの初期化
    init_players(main_win, players);
    // ゲームメイン
    game_main(main_win, base_cal, players);
    // ゲーム終了
    game_end(main_win, players);

    // cursesの終了
    end_curses();

    return 0;
}
