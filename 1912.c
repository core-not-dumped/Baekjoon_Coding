#include <stdio.h>

int main(void)
{
	int n;
	scanf("%d", &n);

	int i, j, num[100000];
	for(i=0;i<n;i++)
		scanf("%d", &num[i]);

	int dp[100000] = {num[0],};
	int ans = num[0];

	for(i=1;i<n;i++)
	{
		dp[i] = dp[i-1]+num[i] > num[i] ? dp[i-1]+num[i] : num[i];
		ans = ans > dp[i] ? ans : dp[i];
	}

	printf("%d\n", ans);

	return 0;
}
