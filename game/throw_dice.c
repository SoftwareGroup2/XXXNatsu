#include <stdio.h>
#include <stdlib.h>

int throw_dice(int n)
{
	if(n == 0)
		return 0;
	else
		return ((rand()%n)+1);
}

//関数単体テスト
int main(void)
{
	srand(1);
	int i,j;

	for(i = 0; i < 10; i++){
		for(j = 0; j < 50; j++){
			printf("%d",throw_dice(i));
		}
		puts("");
	}

	return 0;
}
