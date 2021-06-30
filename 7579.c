#include <stdio.h>

int max(int a, int b)
{
	if(a > b)	return a;
	else	return b;
}

int main(void)
{
	int N, M;
	scanf("%d %d", &N, &M);

	int i, j, m[100], c[100];
	for(i=0;i<N;i++)
		scanf("%d", &m[i]);
	for(i=0;i<N;i++)
		scanf("%d", &c[i]);

	int dp[10001] = {0,};
	for(i=0;i<N;i++)
	{
		for(j=10000;j>0;j--)
		{
			if(dp[j] && j + c[i] <= 10000)
			{
				dp[j + c[i]] = max(dp[j + c[i]] , dp[j] + m[i]);
			}
		}
		dp[c[i]] = max(dp[c[i]], m[i]);
	}

	for(i=0;i<10000;i++)
	{
		if(dp[i] >= M)
		{
			printf("%d\n", i);
			return 0;
		}
	}
}
