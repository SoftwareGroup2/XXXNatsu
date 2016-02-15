#ifndef _DISP_GAME_WINDOW_H_
#define _DISP_GAME_WINDOW_H_
void create_cal(WINDOW *win, int y, int x,PLAYER_T p[]);
void create_info(WINDOW *win,int y,int x,PLAYER_T p[]);
void create_ive(WINDOW *win,int y,int x,PLAYER_T p);
void main_2(WINDOW *win, PLAYER_T players[4], int player_id);
#endif // _DISP_GAME_WINDOW_H_
