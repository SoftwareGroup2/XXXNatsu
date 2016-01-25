// プレイヤーの移動
// ステータスの変更

#include "def.h"
#include "var.h"

#include "throw_dice.h"

void move_player(PLAYER_T *player){
    int move_day;

    move_day = throw_dice(6);

    if (player->day + move_day <= CALENDER_LEN) {
        player->day += move_day;

        // 各種ステータスの変更
        player->enhance_p += player->calender[player->day].enhance_p;
        player->task_p += player->calender[player->day].task_p;
        player->money_p += player->calender[player->day].money_p;
    }else{
        // ゲームクリアした際の処理
    }
}
