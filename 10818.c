#include <stdio.h>

int main(void)
{
	int N;
	scanf("%d", &N);

	int i, a;
	int min = 1000000;
	int max = -1000000;
	for(i=0;i<N;i++)
	{
		scanf("%d", &a);
		if(min > a)	min = a;
		if(max < a)	max = a;
	}

	printf("%d %d\n", min, max);

	return 0;
}
