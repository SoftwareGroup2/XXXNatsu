#include <curses.h>
#include <locale.h>

#include "use_curses.h"
#include "def.h"
#include "var.h"

#include "disp_game_window.h"

void set(PLAYER_T p[])
{
    int i;

    for(i=0;i<4;i++){
        sprintf(p[i].name,"aaaaaaaaaa");
        p[i].grade = 1;
        p[i].club  = 1;
        p[i].girlfriend = 0;
        p[i].enhance_p = 99999;
        p[i].task_p = 99999;
        p[i].money_p = 99999;
        p[i].day = 1;
    }
}

int main(){
    WINDOW *win;
    PLAYER_T players[4];
    int player_id = 0;
    char c;

    set(players);

    setlocale(LC_ALL,"");

    /* 初期化 */
    initscr();

    /* エコー／バッファリング禁止 */
    noecho();
    cbreak();


    /* 全体ウィンドウ作成 */
    win = newwin(35,100,0,0);
    box(win,'|','-');

    /* サブウィンドウ作成 */
    main_2(win,players,player_id);

    /* メッセージ描画 */
    while((c = wgetch(win)) != 0x1b){
    }

    /* 後処理 */
    wclear(win);
    wrefresh(win);
    endwin();

    return 0;
}
