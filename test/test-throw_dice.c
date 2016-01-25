#include <stdio.h>
#include "throw_dice.h"

int main(void){
    int i;
    for (i = 0; i < 30; i++) {
        printf("1~6 : %d\n", throw_dice(6));
    }

    return 0;
}
