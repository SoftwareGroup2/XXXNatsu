// 現在日付が最後のプレイヤーを返す

#include "def.h"
#include "var.h"

// def.hあたりでPLAYER_SIZEを定義したほうがいいと思う。。。
#define PLAYER_SIZE 4

int select_active_player(PLAYER_T *players){
    int i;
    int id, late_day;

    // 0番目のプレイヤーで初期化
    id = 0;
    late_day = players[0].day;

    for (i = 1; i < PLAYER_SIZE; i++) {
        // 同じ場合はidが小さい人を優先ってことで
        if (late_day > players[i].day ) {
            id=i;
            late_day = players[i].day;
        }
    }

    return id;
}
