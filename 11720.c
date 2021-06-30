#include <stdio.h>

int main(void)
{
	int N;
	scanf("%d", &N);

	char num[101];
	scanf("%s", num);

	int i, sum = 0;
	for(i=0;i<N;i++)
		sum += num[i]-48;

	printf("%d\n", sum);

	return 0;
}
