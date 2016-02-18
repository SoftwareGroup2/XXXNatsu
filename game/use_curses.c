#include <curses.h>
#include <locale.h>

#include "use_curses.h"

// cursesを使うための初期化
void init_curses(void){
    // 日本語を利用するための宣言k
    setlocale(LC_ALL,"");

    // 初期化
    initscr();
    // 入力に関する設定
    noecho();               // 入力した文字を画面に出力させない
    keypad(stdscr, true);   // キーボード入力を有効
    // wtimeout(stdscr, 100);  // 100ミリ秒でgetchをタイムアウ
    cbreak();               // 入力を即座にプログラムに渡す(bakc spaceによる文字の訂正ができなくなる)
    curs_set(0);            // カーソルを非表示に 1 でカーソルを表示 (環境依存でうまくいかないらしい)

    // 色の初期化 //
    start_color(); // カラーを有効にする
    use_default_colors(); // 端末デフォルト設定を-1で呼び出せるようにする

    // 色ペアの登録 FONT_hoge を use_curses.h に記述してから使うようにする
    // init_pair( 登録番号, 文字色, 背景色);
    init_pair(FONT_NORMAL, COLOR_WHITE, COLOR_BLACK);
    init_pair(FONT_NORMAL_SELECT, COLOR_BLACK, COLOR_WHITE);
}

// qが押されるまで終了待ち
void wwait_q(WINDOW *win){
    wtimeout(stdscr, 100);
    cbreak();
    while (wgetch(win) != 'q');
}


// cursesの終了処理
void end_curses(void){
    endwin();
}
