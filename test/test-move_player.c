#include <stdio.h>
#include <string.h>

#include "def.h"
#include "var.h"

#include "program_init.h"
#include "init_calender.h"
#include "move_player.h"

int main(void){
    PLAYER_T player;
    TROUT_T base_cal[CALENDER_KIND][CALENDER_LEN+1];

    program_init(base_cal);

    strncpy(player.name, "aaa", 10);
    player.grade = 3;
    player.club = CLUB_SPORT;
    player.girlfriend = 1;

    init_calender(base_cal, player.grade, player.club, player.girlfriend, player.calender);
    // とりあえず各種カレンダーを初期化して表示まで
    disp_calender(player.calender);


    // 10回ぐらい適当に行動させて、その時々のステータスを表示する
    int old_day;
    int i;
    for (i = 0; i < 10; i++) {
        old_day = player.day;
        move_player(&player);
        printf("%10s: %d\n", "出目", old_day-player.day);
        puts("");
        printf("%10s: %d\n", "日付", player.day);
        printf("%10s: %d\n", "充実ポイント", player.day);
        printf("%10s: %d\n", "課題ポイント", player.day);
        printf("%10s: %d\n", "金", player.day);
    }

    return 0;
}
