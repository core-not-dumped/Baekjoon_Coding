#include <stdio.h>

int main(void)
{
	int N, K;
	scanf("%d %d", &N, &K);

	int i;
	int W[100], V[100];
	for(i=0;i<N;i++)
		scanf("%d %d", &W[i], &V[i]);

	int j;
	int dp[100001] = {1,};
	for(i=0;i<N;i++)
	{
		for(j=K-W[i];j>=0;j--)
		{
			if(dp[j])
				dp[j+W[i]] = dp[j+W[i]] > dp[j]+V[i] ? dp[j+W[i]] : dp[j]+V[i];
		}
	}

	int max = 0;
	for(i=0;i<K+1;i++)
	{
		if(max < dp[i])	max = dp[i];
	}
		
	printf("%d\n", --max);

	return 0;
}
