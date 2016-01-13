#include <curses.h>
#include <locale.h>

// cursesを使うための初期化
void init_curses(void){
    // 日本語を利用するための宣言k
    setlocale(LC_ALL,"");

    // 初期化
    initscr();
    // 入力に関する設定
    noecho();               // 入力した文字を画面に出力させない
    keypad(stdscr, true);   // キーボード入力を有効
    wtimeout(stdscr, 100);  // 100ミリ秒でgetchをタイムアウ
    cbreak();               // 入力を即座にプログラムに渡す(bakc spaceによる文字の訂正ができなくなる)
}

// cursesの終了処理
void end_curses(void){
    endwin();
}

int main(void){
    // cursesを使うための初期化
    init_curses();

    // qが入力されるまで待機
    while (getch() != 'q'){
        mvprintw(10,10,"あああ");
        refresh();
    }

    // cursesの終了処理
    end_curses();

    return 0;
}
