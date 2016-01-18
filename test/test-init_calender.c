#include <stdio.h>
#include <string.h>

#include "def.h"
#include "var.h"

#include "program_init.h"
#include "init_calender.h"

int main(){
    // テストなのでプレイヤーを1人だけ生成
    PLAYER_T player;
    TROUT_T base_cal[CALENDER_KIND][CALENDER_LEN+1];

    // base_calの初期化
    program_init(base_cal);

    // 最低限必要なplayerの初期ステータスを適当に代入
    strncpy(player.name, "aaaaa", 10);
    player.grade = 3;
    player.club = CLUB_SPORT;
    player.girlfriend = 1;

    init_calender(base_cal, player.grade, player.club, player.girlfriend, player.calender);

    // disp_calendr関数はprogram_initで実装
    disp_calender(player.calender);

    return 0;
}
