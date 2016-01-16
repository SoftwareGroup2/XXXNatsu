#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "def.h"
#include "var.h"
#include "select_active_player.h"

char name[100];         // 名前
int grade;              // 学年
int club;               // 部活(帰宅部/運動部/文化部)
int girlfriend;         // 彼女(いる/いない)
int enhance_p;          // 充実ポイント
int task_p;             // 課題ポイント
int money_p;            // 金
int day;                // 現在何日目か

int main(){
    int i;
    PLAYER_T players[4];

    srand((unsigned)time(NULL));

    for (i = 0; i < 4; i++) {
        players[i].day = rand()%44;
        printf("player %d : %3d\n", i, players[i].day);
    }

    printf("active_player ID: %3d\n", select_active_player(players));

    return 0;
}
