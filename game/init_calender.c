#include <string.h>
#include <stdio.h>

#include "def.h"
#include "var.h"

// コンテンツ、一つ一つの項目をコピーする
// 使わなくても問題なさそうなので、使わない。
// 将来的に使うかもしれないから一応残しておく。。
void cpy_cal_data(TROUT_T cal, TROUT_T *player_cal){
    strncpy(player_cal->content, cal.content, CONTENT_LEN);
    player_cal->enhance_p = cal.enhance_p;
    player_cal->task_p = cal.task_p;
    player_cal->money_p = cal.money_p;
    player_cal->move_day = cal.move_day;
}

// 内容の入っている部分のみ上書きする
void over_write_calender(TROUT_T *base_cal, TROUT_T *player_cal){
    int i;
    for (i = 1; i <= CALENDER_LEN; i++) {
        // コンテンツがNONEではなかったら
        // strncmpは一致で0を返す
        if (strncmp(base_cal[i].content, "NONE", 4) != 0){
            player_cal[i] = base_cal[i];
//            cpy_cal_data( base_cal[i], &player_cal[i]);
        }
    }
}

void init_calender(TROUT_T calender[CALENDER_KIND][CALENDER_LEN+1], int grade, int club, int girlfriend, TROUT_T *player_cal){
    // 構造体のコピーは代入で利用できる(らしい)
    // 初期カレンダーは単純にコピー
    over_write_calender(calender[CK_BASE], player_cal);

    // 学年
    over_write_calender(calender[grade], player_cal);
    // 部活
    if (club != 0) // 部活動に入っていたら
        over_write_calender(calender[5+club], player_cal);
    // 彼女
    if (girlfriend != 0) // 彼女がいたら
        over_write_calender(calender[CK_GF], player_cal);
}
