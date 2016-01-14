// init_player$B$OA0Ds$H$7$F(Bcurses$B$N(Binit,end$B$,B>4X?t$G<B9T$5$l$k$b$N$H9M$($k(B

#include <stdio.h>
#include <curses.h>

#include "def.h"
#include "var.h"
#include "use_curses.h"

int init_player(PLAYER_T *player);

int init_player(WINDOW *win, PLAYER_T *player){
    // $B$H$j$"$($:(Bplayer$B9=B$BN$K%W%l%$%d!<L>$,$J$$$N$GE,Ev$K:n$C$F$*$/!#(B
    char player_name[100];
    // memo: curses$B$N:BI8;XDj$G$O!"(By,x $B$N=g$G;XDj$9$k(B
    nocbreak();               // bakc space$B$K$h$kJ8;z$ND{@5$,$G$-$k(B
    mvwaddstr(win, 1, 3, "$B%W%l%$%d!<L>(B: ") getstr(player_name);

    return 0;
}

int main(void){
    init_curses(void);

    PLAYER_T player1;
    WINDOW *win;

    // $B%&%#%s%I%&$,$"$k$H2]Dx$9$k!#(B
    win = newwin(LINES,COLS-1,0,0);
    box(win,'|','-');

    init_player(win, player1);

    end_curses();

    return 0;
}
