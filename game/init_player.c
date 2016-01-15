// init_playerは前提としてcursesのinit,endが他関数で実行されるものと考える
//

#include <stdio.h>
#include <curses.h>

#include "def.h"
#include "var.h"
#include "use_curses.h"

int init_player(WINDOW *, PLAYER_T *);

// 名前の入力
int input_player_name(WINDOW *win, PLAYER_T *player, int y, int x){
    echo();     // 入力した文字を画面に出力
    nocbreak(); // bakc spaceによる文字の訂正ができる
    curs_set(1);// カーソルを表示

    // このへんの座標指定は適当
    mvwaddstr(win, y, x, "プレイヤー名: ");
    wgetstr(win, player->name);
    wrefresh(win);


    return 0;  // 一応正常終了で0を返すって事で
}

// 学年の選択
int select_grade(WINDOW *win, PLAYER_T *player, int y, int x){
    int grade=0;
    char c;
    noecho();   // 入力した文字を画面に出力
    cbreak();   // 入力をすぐに反映
    curs_set(0);// カーソルを非表示

    mvwaddstr(win, y, x, "学年: ");

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
        int pos_x;
        for (pos_x = 0; pos_x < 5; pos_x++) {
            if (pos_x == grade) {
                // 選択時の色を使う
                wattrset(win, COLOR_PAIR(FONT_NORMAL_SELECT));
            }else{
                // 非選択時の色を使う
                wattrset(win, COLOR_PAIR(FONT_NORMAL));
            }
            mvwaddch(win, y, x+7+pos_x*2, pos_x+'1');
        }
        wrefresh(win);
        c = wgetch(win);
    }while(c != '\n');

    player->grade = grade+1;

    return 0; // 正常終了で0を返す
}

// 部活を選択
int select_club(WINDOW *win, PLAYER_T *player, int y, int x){
    int club=0;
    char c;

    char club_list[][12] = {"帰宅部", "運動部", "文化部"};

    noecho(); // 入力した文字を画面に出力
    cbreak(); // 入力をすぐに反映
    curs_set(0);// カーソルを非表示

    mvwaddstr(win, y, x, "クラブ: ");

    c = '\0';
    do{
        switch(c){
            case 'd':
                // case KEY_DOWN: // KEY_DOWN などは環境依存
                club = (club+2)%3;
                break;
            case 'u':
                //case KEY_UP:
                club = (club+1)%3;
                break;
            default:
                break;
        }
        int s_club;
        for (s_club = 0; s_club < 3; s_club++) {
            if (s_club == club) {
                // 選択時の色を使う
                wattrset(win, COLOR_PAIR(FONT_NORMAL_SELECT));
            }else{
                // 非選択時の色を使う
                wattrset(win, COLOR_PAIR(FONT_NORMAL));
            }
            mvwaddstr(win, y, x+8+s_club*7, club_list[s_club]);
        }
        wrefresh(win);
        c = wgetch(win);
    }while(c != '\n');
    player->club = club;

    return 0;  // 正常終了で0を返す
}

// ユーザの入力を含まない初期値設定
int set_default_status(PLAYER_T *player){
    player->enhance_p   = 100;  // 充実ポイント
    player->task_p      = 3000; // 課題ポイント
    player->girlfriend  = 0;    // 彼女の有無 (確率でやりたい)
    player->money_p     = 1000; // 金
    player->day         = 0;    // 現在の日付

    return 0;
}

// ユーザ情報の入力メイン関数
int init_player(WINDOW *win, PLAYER_T *player){
    // memo: cursesの座標指定では、y,x の順で指定する
    mvwaddstr(win, 1, 10, "プレイヤー情報を入力 ->:u  <-:d");
    // プレイヤー名の入力
    input_player_name(win, player, 2, 3);
    // 学年の選択
    select_grade(win, player, 3, 11);
    // 部活の選択
    select_club(win, player, 4, 9);

    // デフォルトステータスの入力
    set_default_status(player);

    // q キーを入力するまで待機
    wattrset(win, COLOR_PAIR(FONT_NORMAL));
    mvwaddstr(win, 5, 1, "qキーを押して終了");

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
