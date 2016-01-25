#include <stdio.h>
#include <stdlib.h>
#include "throw_dice.h"

// 1 ~ n までの整数を返す
int throw_dice(int n)
{
	if(n == 0)
		return 0;
	else
		return ((rand()%n)+1);
}
