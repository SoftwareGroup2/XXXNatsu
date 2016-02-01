#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "def.h"
#include "var.h"

#define MAX_ROW_SIZE 1000

// 元のカレンダーをグローバル変数で持つって仕様を完全に無視してしまった。
// なんだか問題が出たら誰か修正して... H28/1/15

// カレンダーの初期化
void init_calender_data(TROUT_T *cal){
    int i;
    for (i = 1; i <= CALENDER_LEN; i++) {
        strncpy(cal[i].content, "NONE\0", 5);
    }
}

// 1つのカレンダーを構造体配列に読み込む
int load_base_calender(TROUT_T *cal, char *file_name){
    int day, enhance_p, task_p, money_p, move_day;
    char row[MAX_ROW_SIZE]; // データ1行保持用バッファ
    char content[CONTENT_LEN];

    FILE *fp;

    if ((fp = fopen( file_name, "r")) == NULL) {
        printf("ファイル: %s が開けません\n", file_name);
        return FALSE;
    }

    // まず初期化
    init_calender_data(cal);

    while(fgets(row, MAX_ROW_SIZE, fp) != NULL){
        sscanf(row,"%d,%[^,],%d,%d,%d,%d", &day, content, &enhance_p, &task_p, &money_p, &move_day);
        strncpy(cal[day].content, content, CONTENT_LEN);
        cal[day].enhance_p = enhance_p;
        cal[day].task_p    = task_p;
        cal[day].money_p   = money_p;
        cal[day].move_day  = move_day;
    }

    return TRUE;
}

// カレンダーの内容を表示
void disp_calender(TROUT_T *cal){
    int i;
    printf("%4s,%35s,%8s,%8s,%8s,%8s\n","日付","内容(冒頭のみ)","充実","課題","金","N日");
    for (i = 1; i <= CALENDER_LEN; i++) {
        printf("%4d,%35s,%8d,%8d,%8d,%8d\n", i, cal[i].content, cal[i].enhance_p, cal[i].task_p, cal[i].money_p, cal[i].move_day);
    }
}

int program_init(TROUT_T base_cal[CALENDER_KIND][CALENDER_LEN+1]){
    srand((unsigned)time(NULL));

    // 配列にすべてのカレンダーを読み込む
    // 適宜ファイル名を変更して読み込み部分を作成する
    if(load_base_calender(base_cal[CK_BASE], "../data/base.csv")==FALSE) return FALSE;
    if(load_base_calender(base_cal[CK_1], "../data/grade1.csv")==FALSE) return FALSE;
    if(load_base_calender(base_cal[CK_2], "../data/grade2.csv") == FALSE) return FALSE;
    if(load_base_calender(base_cal[CK_3], "../data/grade3.csv") == FALSE) return FALSE;
    if(load_base_calender(base_cal[CK_4], "../data/grade4.csv") == FALSE) return FALSE;
    if(load_base_calender(base_cal[CK_5], "../data/grade5.csv") == FALSE) return FALSE;
    if(load_base_calender(base_cal[CK_SPORT], "../data/sport.csv") == FALSE) return FALSE;
    if(load_base_calender(base_cal[CK_CULTURE], "../data/culture.csv") == FALSE) return FALSE;
    if(load_base_calender(base_cal[CK_GF], "../data/gf.csv") == FALSE) return FALSE;

    return TRUE;
}
