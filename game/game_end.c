#include <curses.h>

#include "def.h"
#include "var.h"

#include "use_curses.h"

void change_int(int *a, int *b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

// void disp_ranking(WINDOW *win, PLAYER_T players[]){
// }

// ゲーム終了時にプレイヤーのいろいろを表示する
void game_end(WINDOW *win, PLAYER_T players[]){
    int i, j, r_cnt=0;
    int id[]={0,1,2,3};
    int use_id[4] = {0};

    int x_pos = 100/2 - (40/2);
    int yy;

    // とりあえず，充実ポイント順にソート
    for (i = 0; i < 4; i++) {
        for (j = i; j < 4; j++) {
            if (players[id[j]].enhance_p > players[id[i]].enhance_p)
                change_int(&id[j], &id[i]);
        }
    }

    // タイトルの表示
    box(win,'|','-');
    wrefresh(win);

    yy = 5;
    mvwprintw(win, yy, x_pos+15,"XXXの夏休み");
    mvwprintw(win, yy+2, x_pos+50," 製作: 2班");

    // 課題ポイントが残っていない人
    for (i = 0; i < 4; i++) {
        if (players[id[i]].task_p <= 0){
            mvwprintw(win,r_cnt+20, x_pos, "%d位: %s, 充実P: %6d 課題P: %6d", r_cnt+1, players[id[i]].name, players[id[i]].enhance_p, players[id[i]].task_p);
            r_cnt++;
            use_id[i] = 1;
        }
    }

    // 課題ポイントが残っている人
    for (i = 0; i < 4; i++) {
        if (use_id[i] == 0){
            mvwprintw(win,r_cnt+20, x_pos, "%d位: %s, 充実P: %6d 課題P: %6d", r_cnt+1, players[id[i]].name, players[id[i]].enhance_p, players[id[i]].task_p);
            r_cnt++;
        }
    }

    mvwprintw(win, 30, x_pos+4, "qキーを押してゲームを終了します。");

    wwait_q(win);
}

