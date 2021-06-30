#include <stdio.h>

int main(void)
{
	int N;
	scanf("%d", &N);

	int i = 0;
	int sum = 0;
	while(sum < N)
	{
		i++;
		sum += i;
	}

	int diff = sum-N;
	if(i%2 == 1)	printf("%d/%d\n", 1+diff, i-diff);
	else	printf("%d/%d\n", i-diff, 1+diff);

	return 0;
}
