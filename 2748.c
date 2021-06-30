#include <stdio.h>

int main(void)
{
	int N, i;
	scanf("%d", &N);
	
	long long F[100];
	F[0] = 0;
	F[1] = 1;

	for(i=0;i<N-1;i++)
		F[i+2] = F[i] + F[i+1];

	printf("%lld\n", F[N]);

	return 0;
}
