// 複数プレイヤーを初期化するための関数
// init_players

#include <curses.h>

#include "def.h"
#include "var.h"
#include "use_curses.h"
#include "init_player.h"

void init_players(WINDOW *win, PLAYER_T players[]){
    int i;
    for (i = 0; i < 4; i++) {
        init_player(win, &players[i]);
        wclear(win);
        box(win,'|','-');  // 画面を初期化して枠線を描画
    }
}

// きちんと代入されているか、テスト用関数
void print_players_status(PLAYER_T players[]){
    int i;
    for (i = 0; i < 4; i++) {
        printf("----------player %d status----------\n", i);
        printf("%5s : %s\n", "名前", players[i].name);
        printf("%5s : %d\n", "学年", players[i].grade);
        printf("%5s : %d\n", "部活", players[i].club);
        printf("%5s : %d\n\n", "彼女", players[i].girlfriend);
        printf("%5s : %d\n", "充実", players[i].enhance_p);
        printf("%5s : %d\n", "課題", players[i].task_p);
        printf("%5s : %d\n", "金", players[i].money_p);
        printf("%5s : %d\n", "日付", players[i].day);
    }
}
