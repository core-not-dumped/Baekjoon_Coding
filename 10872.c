#include <stdio.h>

int fact(int N)
{
	if(!N)	return 1;
	return N*fact(N-1);
}

int main(void)
{
	int N;
	scanf("%d", &N);

	printf("%d\n",fact(N));

	return 0;
}
