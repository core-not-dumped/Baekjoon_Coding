#include <stdio.h>
#include <limits.h>

struct matrix{
	int r,c;
}m[501];

int main(void)
{
	int N;
	scanf("%d", &N);
	
	int i, j, k;
	for(i=1;i<=N;i++)
		scanf("%d %d", &m[i].r, &m[i].c);
	
	int dp[501][501];
	int num[501][501];
	
	for(i=1;i<=N;i++)
		num[i-1][i] = i;
	
	for(i=2;i<=N;i++)
	{
		for(j=0;j<=N-i;j++)
		{
			dp[j][i+j] = INT_MAX;
			for(k=j+1;k<=i+j-1;k++)
			{
				int tmp;
				tmp = dp[j][k] + dp[k][i+j];
				tmp += m[j+1].r * m[k].c * m[i+j].c;
				
				if(dp[j][i+j] > tmp)
				{
					dp[j][i+j] = tmp;
					num[j][i+j] = k;
				}
			}
		}
	}
	
	printf("%d", dp[0][N]);
	
	return 0;
}
