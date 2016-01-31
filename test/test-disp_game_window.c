#include <curses.h>

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

int main(void){
    WINDOW *win,*cal,*ive,*info;
    char c;
    int i;
    PLAYER_T p[4];
    char str[2000];

    // cursesの初期化
    init_curses();

    // プレイヤーステータスの初期化
    set(p);

    // プレイヤーを適当な位置に移動
    p[0].day = 0;
    p[1].day = 10;
    p[2].day = 25;
    p[3].day = 40;

    /* 全体ウィンドウ作成 */
    i=0;

    win = newwin(35,99,0,0);
    box(win,'|','-');

    // この部分をmain以外のどこかに移行が必要
    sprintf(str,"%sの夏休み",p[i].name);
    mvwaddstr(win,1,(COLS-1)/2,str);

    /* カレンダーウィンドウ作成 */
    cal = subwin(win,25,50,2,0);
    create_cal(cal,1,1,p);
    wrefresh(cal);

    /* イベントウィンドウ作成 */
    ive = subwin(win,25,49,2,50);
    create_ive(ive);

    /* プレイヤー情報ウィンドウ作成 */
    info = subwin(win,8,99,27,0);
    create_info(info,1,1,p);
    wrefresh(info);

    /* Escが押されるまで待機 */
    while((c = wgetch(win)) != 0x1b){
        wrefresh(win);
    }

    /* 後処理 */
    wclear(win);
    wrefresh(win);

    end_curses();
}
