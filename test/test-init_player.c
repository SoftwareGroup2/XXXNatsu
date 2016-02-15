// init_playerをテストする

#include <stdio.h>
#include <curses.h>

#include <stdlib.h>
#include <time.h>

#include "def.h"
#include "var.h"
#include "use_curses.h"
#include "init_player.h"
#include "program_init.h"


int main(void){

    TROUT_T base_cal[CALENDER_KIND][CALENDER_LEN+1];

    program_init(base_cal);


    init_curses();

    PLAYER_T player1;

    // windowの作成処理
    WINDOW *win;
    win = newwin(LINES,COLS-1,0,0);
    box(win,'|','-');

    // 作成した関数
    init_player(win, &player1,base_cal);

    // windowの終了処理
    wclear(win);
    wrefresh(win);

    end_curses();

    printf("名前: %s\n",player1.name);
    printf("学年: %d\n",player1.grade);
    printf("部活: %d\n",player1.club);
    printf("彼女: %d\n\n",player1.girlfriend);
    printf("充実: %d\n",player1.enhance_p);
    printf("課題: %d\n",player1.task_p);
    printf("日付: %d\n",player1.day);

    disp_calender(player1.calender);

    return 0;
}
