#include <stdio.h>
#include <limits.h>

int main(void)
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int f_num;
		scanf("%d", &f_num);
		
		int dp[5001][5001];
		int f[5001] = {0,};
		int i, j, k;
		for(i=1;i<=f_num;i++)
			scanf("%d", &f[i]);
			
		for(i=2;i<=f_num;i++)
			f[i] += f[i-1];
			
		int num[5001][5001];
		for(i=1;i<=f_num;i++)
			num[i-1][i] = i;
		
		for(i=2;i<=f_num;i++)
		{
			for(j=0;j<=f_num-i;j++)
			{
				dp[j][i+j] = INT_MAX;
				for(k=num[j][i+j-1];k<=num[j+1][i+j];k++)
				{
					int tmp;
					tmp = dp[j][k] + dp[k][i+j] + f[i+j] - f[j];
					
					if(dp[j][i+j] > tmp)
					{
						num[j][i+j] = k;
						dp[j][i+j] = tmp;
					}
				}
			}
		}
		
		printf("%d\n", dp[0][f_num]);
	}
	
	return 0;
}
