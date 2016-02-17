#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <curses.h>

#include "def.h"
#include "var.h"

#include "use_curses.h"
#include "game_end.h"

int main(){
    int i;
    WINDOW *win;
    PLAYER_T players[4];

    srand(114514);

    strcpy(players[0].name, "日本語ああ");
    strcpy(players[1].name, "あうい");
    strcpy(players[2].name, "123456789012345");
    strcpy(players[3].name, "Fooooo");

    players[0].task_p = 0;
    players[1].task_p = 0;
    players[2].task_p = 10;
    players[3].task_p = -10;

    for (i = 0; i < 4; i++) {
        players[i].enhance_p = rand()%10;
    }

    init_curses();

    win = newwin(35,100,0,0);
    box(win,'|','-');

    game_end(win, players);

    end_curses();

    return 0;
}
