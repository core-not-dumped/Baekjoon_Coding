#include <stdio.h>

int dp[20][20][20];

int w(int a, int b, int c)
{
	if(a<=0 || b<=0 || c<=0)	return 1;

	if(a>20 || b>20 || c>20)	return 1048576;

	if(dp[a-1][b-1][c-1])	return dp[a-1][b-1][c-1];

	if(a<b && b<c)
		return dp[a-1][b-1][c-1] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
	else
		return dp[a-1][b-1][c-1] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
}

int main(void)
{
	while(1)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		if(a == -1 && b == -1 && c == -1)
		return 0;

		printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
	}

	return 0;
}
