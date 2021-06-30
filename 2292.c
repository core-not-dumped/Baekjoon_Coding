#include <stdio.h>

int main(void)
{
	int N;
	scanf("%d", &N);
	if(!(N-1))	{ printf("1\n");	return 0; }

	N--;
	int bound = 1;
	while(N > 0)
	{
		bound++;
		N -= (6*bound-6);
	}

	printf("%d\n", bound);

	return 0;
}
