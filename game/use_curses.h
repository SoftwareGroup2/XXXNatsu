#ifndef _USE_CURSES_H_
#define _USE_CURSES_H_

enum FONT { FONT_NORMAL, FONT_NORMAL_SELECT };

void init_curses(void);
void end_curses(void);
void wwait_q(WINDOW *win);

#endif // _USE_CURSES_H_
