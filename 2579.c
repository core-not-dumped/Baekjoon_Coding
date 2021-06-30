#include <stdio.h>
#include <memory.h>

int big(int a, int b)
{
	return (a>b)?a:b;
}

int main(void)
{
	int dp1[302];
	int dp2[302];
	int stair[302];
	memset(dp1,0,sizeof(dp1));
	memset(dp2,0,sizeof(dp2));
	
	int N;
	scanf("%d", &N);

	int i;
	for(i=0;i<N;i++)
		scanf("%d", &stair[i]);
	
	dp1[0] = stair[0];
	dp1[1] = stair[1];
	dp2[1] = stair[0] + stair[1];

	for(i=2;i<N;i++)
	{
		dp1[i] = big(dp1[i-2], dp2[i-2]) + stair[i];
		dp2[i] = dp1[i-1] + stair[i];
	}

	printf("%d\n", big(dp1[N-1], dp2[N-1]));

	return 0;
}
