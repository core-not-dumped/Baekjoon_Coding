#include <stdio.h>

int main(void)
{
	int i;
	int p = 1e9 + 9;
	int dp[1000001] = {0,1,2,4,};
	for(i=4;i<=1000000;i++)
		dp[i] = ((dp[i-3] + dp[i-2]) % p + dp[i-1]) % p;

	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		printf("%d\n", dp[n]);
	}
	
	return 0;
}
