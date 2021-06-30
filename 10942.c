#include <stdio.h>

int main(void)
{
	int N;
	scanf("%d", &N);
	
	int i, j;
	int arr[2000];
	for(i=0;i<N;i++)
		scanf("%d", &arr[i]);
		
	int dp[2000][2000];
	for(i=0;i<N;i++)	dp[i][i] = 1;
		
	for(i=0;i<N-1;i++)
	{
		if(arr[i] == arr[i+1])	dp[i][i+1] = 1;
		else					dp[i][i+1] = 0;
	}
	
	for(i=2;i<N;i++)
	{
		for(j=0;j<N-i;j++)
		{
			if(dp[j+1][i+j-1])
			{
				if(arr[j] == arr[i+j])
					dp[j][i+j] = 1;
			}
		}
	}
		
	int M;
	scanf("%d", &M);
	while(M--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", dp[a-1][b-1]);
	}
	
	return 0;
}
