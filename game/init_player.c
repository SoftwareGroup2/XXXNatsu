// init_playerは前提としてcursesのinit,endが他関数で実行されるものと考える

#include <stdio.h>
#include <curses.h>

#include "def.h"
#include "var.h"
#include "use_curses.h"

int init_player(WINDOW *, PLAYER_T *);

int init_player(WINDOW *win, PLAYER_T *player){
    // とりあえずplayer構造体にプレイヤー名がないので適当に作っておく。
    char player_name[100];
    char c;
    // memo: cursesの座標指定では、y,x の順で指定する
    echo();               // 入力した文字を画面に出力
    nocbreak(); // bakc spaceによる文字の訂正ができる

    // このへんの座標指定は適当

    // プレイヤー名の入力
    mvwaddstr(win, 1, 3, "プレイヤー名: ");
    wgetstr(win, player_name);
    wrefresh(win);

    mvwaddstr(win, 2, 17, player_name);
    wrefresh(win);

    // 学年の入力
    int grade=0;
    noecho(); // 入力した文字を画面に出力
    cbreak(); // 入力をすぐに反映
    mvwaddstr(win, 4, 3, "学年: ");

    c = '\0';
    do{
        switch(c){
            case 'd':
            // case KEY_DOWN: // KEY_DOWN などは環境依存
                grade = (grade+4)%5;
                break;
            case 'u':
            //case KEY_UP:
                grade = (grade+1)%5;
                break;
            default:
                break;
        }
        mvwaddch(win, 4, 9, grade+'1');
        wrefresh(win);
        c = wgetch(win);
    }while(c != 'q');

    player->grade = grade+1;
    mvwaddch(win, 5, 9, player->grade+'0');

    // q キーを入力するまで待機
    wwait_q(win);

    return 0;
}

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
