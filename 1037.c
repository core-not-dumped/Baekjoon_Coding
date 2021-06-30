#include <stdio.h>

int main(void)
{
	int N;
	scanf("%d", &N);

	int max = 0;
	int min = 999999999;
	int i;
	for(i=0;i<N;i++)
	{
		int num;
		scanf("%d", &num);
		if(num > max)	max = num;
		if(num < min)	min = num;
	}
	printf("%d\n", max*min);

	return 0;
}
