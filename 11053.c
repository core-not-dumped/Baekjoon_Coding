#include <stdio.h>
#include <memory.h>

int main(void)
{
	int N, max, i, j;
	int A[1001], dp[1001];
	memset(dp,0,sizeof(dp));

	scanf("%d", &N);
	for(i=0;i<N;i++)
		scanf("%d", &A[i]);

	dp[0] = 1;
	max = 1;
	for(i=1;i<N;i++)
	{
		for(j=i-1;j>=0;j--)
		{
			if(A[i] > A[j] && dp[i] < dp[j])
				dp[i] = dp[j];
		}

		dp[i]++;
		if(max < dp[i])	max = dp[i];
	}

	printf("%d\n", max);

	return 0;
}
