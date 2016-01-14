#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "def.h"
#include "var.h"

#define MAX_ROW_SIZE 1000

// 1つのカレンダーを構造体配列に読み込む
int load_base_calender(TROUT_T *cal, char *file_name){
    int i;
    int day, enhance_p, task_p, money_p, move_day;
    char row[MAX_ROW_SIZE]; // データ1行保持用バッファ
    char content[CONTENT_LEN];

    FILE *fp;

    if ((fp = fopen( file_name, "r")) == NULL) {
        printf("ファイル: %s が開けません\n", file_name);
        exit(EXIT_FAILURE);
    }

    while(fgets(row, MAX_ROW_SIZE, fp) != NULL){
        sscanf(row,"%d,%[^,],%d,%d,%d,%d", &day, content, &enhance_p, &task_p, &money_p, &move_day);
        strncpy(cal[day].content, content, CONTENT_LEN);
        cal[day].enhance_p = enhance_p;
        cal[day].task_p    = task_p;
        cal[day].money_p   = money_p;
        cal[day].move_day  = move_day;
    }

    return 0;
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

    load_base_calender(base_cal[CK_BASE], "../data/1_basecalender.csv");
    disp_calender(base_cal[CK_BASE]);

    return 0;
}

int main(void) {
    TROUT_T base_cal[CALENDER_KIND][CALENDER_LEN+1];
    program_init(base_cal);
}
