#include <stdio.h>
#include <memory.h>

int main(void)
{
	int n;
	scanf("%d", &n);

	int i, j;
	int dp[502];
	int num[502];
	memset(dp,0,sizeof(dp));
	memset(num,0,sizeof(num));

	for(i=0;i<n;i++)
	{
		for(j=0;j<i+1;j++)
			scanf("%d", &num[j]);

		for(j=i;j>0;j--)
		{
			dp[j] = (dp[j-1] > dp[j]) ? dp[j-1] : dp[j];
			dp[j] += num[j];
		}
		dp[0] = dp[0] + num[0];
	}

	int max = 0;
	for(i=0;i<n;i++)
		if(max < dp[i])	max = dp[i];

	printf("%d\n", max);

	return 0;
}
