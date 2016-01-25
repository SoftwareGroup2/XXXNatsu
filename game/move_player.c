// プレイヤーの移動
// ステータスの変更

#include "def.h"
#include "var.h"

#include "throw_dice.h"

void move_player(PLAYER_T *player){
    int move_day;

    if (player->day <= 44) {
        // プレイヤーが行動する場合
        // 移動マス決定
        move_day = throw_dice(6);
        if (player->day + move_day <= CALENDER_LEN) {
            // プレイヤーを移動させる
            player->day += move_day;
            // 各種ステータスの変更
            player->enhance_p += player->calender[player->day].enhance_p;
            player->task_p += player->calender[player->day].task_p;
            player->money_p += player->calender[player->day].money_p;
        }else{
            // ゲームクリアした際の処理
            player->day = CALENDER_LEN+1; // とりあえず、最終日の次の日に移動
            move_day = 0;
        }
    }else{
        // すでにプレイヤーがゴールしている場合の処理
    }
}