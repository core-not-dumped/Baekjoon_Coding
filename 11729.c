#include <stdio.h>

void Hanoi(int num, int s, int r, int f)
{
	if(num == 1)
	{
		printf("%d %d\n", s, f);
		return;
	}

	Hanoi(num - 1, s, f, r);
	printf("%d %d\n", s, f);
	Hanoi(num - 1, r, s, f);
}

int main(void)
{
	int K;
	scanf("%d", &K);	
	printf("%d\n", (1<<K)-1);
	Hanoi(K,1,2,3);

	return 0;
}
