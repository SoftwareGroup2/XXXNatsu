#include <stdio.h>

#include "def.h"
#include "var.h"
#include "program_init.h"

int main(void) {
    TROUT_T base_cal[CALENDER_KIND][CALENDER_LEN+1];
    program_init(base_cal);

    // きちんと読み込めているかテスト
    disp_calender(base_cal[CK_SPORT]);

    return 0;
}
