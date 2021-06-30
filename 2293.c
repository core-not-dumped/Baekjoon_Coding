#include <stdio.h>

int main(void)
{
	int n, k;
	scanf("%d %d", &n, &k);

	int i, j, coin[100];
	for(i=0;i<n;i++)
		scanf("%d", &coin[i]);

	int dp[10001] = {1,};
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<=k;j++)
		{
			if(j - coin[i] >= 0)
				dp[j] += dp[j - coin[i]];
		}
	}

	printf("%d\n", dp[k]);

	return 0;
}
