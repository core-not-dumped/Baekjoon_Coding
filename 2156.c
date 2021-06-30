#include <stdio.h>
#include <memory.h>

int big(int a, int b)
{
	return (a>b)?a:b;
}

int main(void)
{
	int N;
	scanf("%d", &N);

	int i;
	int gra[10001];
	for(i=0;i<N;i++)
		scanf("%d", &gra[i]);

	int dp1[10001];
	int dp2[10001];
	memset(dp1,0,sizeof(dp1));
	memset(dp2,0,sizeof(dp2));

	dp1[0] = gra[0];
	dp1[1] = gra[1];
	dp2[1] = gra[0] + gra[1];
	dp1[2] = gra[0] + gra[2];
	dp2[2] = gra[1] + gra[2];

	for(i=3;i<N;i++)
	{
		dp1[i] = big(big(dp1[i-2],dp2[i-2]),big(dp1[i-3],dp2[i-3])) + gra[i];
		dp2[i] = dp1[i-1] + gra[i];
	}

	int max;
	max = big(big(dp1[N-1],dp2[N-1]), big(dp1[N-2],dp2[N-2]));
	printf("%d\n", max);

	return 0;
}
