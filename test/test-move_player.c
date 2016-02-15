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

    // ユーザ入力によるプレイヤー情報の初期化
    strncpy(player.name, "aaa", 10);
    player.grade = 3;
    player.club = CLUB_SPORT;
    player.girlfriend = 1;

    // 定数としてのプレイヤー情報初期化
    player.enhance_p   = 100;  // 充実ポイント
    player.task_p      = 3000; // 課題ポイント
    player.girlfriend  = 0;    // 彼女の有無 (確率でやりたい)
    player.money_p     = 1000; // 金
    player.day         = 0;    // 現在の日付

    init_calender(base_cal, player.grade, player.club, player.girlfriend, player.calender);
    // とりあえず各種カレンダーを初期化して表示まで
    disp_calender(player.calender);


    // 適当に行動させて、その時々のステータスを表示する
    int old_day;
    int i;
    for (i = 0; i < 15; i++) {
        old_day = player.day;
        move_player(&player);
        printf("----------------------------------------\n");
        printf("%20s: %d\n", "出目", player.day-old_day);
        puts("");
        printf("%20s: %d\n", "日付", player.day);
        printf("%20s: %d\n", "充実ポイント", player.enhance_p);
        printf("%20s: %d\n", "課題ポイント", player.task_p);
        printf("%20s: %d\n", "金", player.money_p);
    }

    return 0;
}
