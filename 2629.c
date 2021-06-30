#include <stdio.h>

int main(void)
{
	int N;
	scanf("%d", &N);

	int i, j;
	int chu[30];
	for(i=0;i<N;i++)
		scanf("%d", &chu[i]);

	int dp[100001];
	int ch = 1;
	dp[chu[0]] = 1;
	for(i=1;i<N;i++)
	{
		ch <<= 1;
		for(j=0;j<=100000;j++)
		{
			if(dp[j] & (ch >> 1))
			{
				if(j + chu[i] <= 100000)
					dp[j + chu[i]] |= ch;
				if(j - chu[i] > 0)
					dp[j - chu[i]] |= ch;
				else
					dp[chu[i] - j] |= ch;

				dp[j] |= ch;
			}
		}
		dp[chu[i]] |= ch;
	}

	int M;
	scanf("%d", &M);
	while(M--)
	{
		int gu;
		scanf("%d", &gu);
		if(dp[gu])	printf("Y ");
		else		printf("N ");
	}
	printf("\n");

	return 0;
}
