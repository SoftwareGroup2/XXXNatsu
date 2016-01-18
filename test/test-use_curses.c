#include <curses.h>

#include "use_curses.h"

int main(void){
    // cursesを使うための初期化
    init_curses();

    // qが入力されるまで待機
    do{
        attrset(COLOR_PAIR(FONT_NORMAL_SELECT));
        mvprintw(10,10,"あああ");
        attrset(COLOR_PAIR(FONT_NORMAL));
        mvprintw(11,10,"qを押して終了");
        refresh();
    }while(getch() != 'q');

    // cursesの終了処理
    end_curses();

    return 0;
}
