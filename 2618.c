#include <stdio.h>
#include <stdlib.h>

typedef struct ROAD{
	int x, y;
}road;

int main(void)
{
	int N, W;
	scanf("%d", &N);
	scanf("%d", &W);

	int i, j, k;
	road R[1001]; 
	for(i=1;i<=W;i++)
		scanf("%d %d", &R[i].x, &R[i].y);

	R[0].x = 1;
	R[0].y = 1;

	int dis[101][101];
	for(i=0;i<=W;i++)
	{
		for(j=i+1;j<=W;j++)
			dis[i][j] = abs(R[i].x - R[j].x) + abs(R[i].y - R[j].y);
	}

	int dp2[101][101];
	int dp[101][101] = {0};
	int px[2] = {-1,0};
	int py[2] = {0,-1};
	dp[1][0] = abs(1-R[1].x) + abs(1-R[1].y);
	dp[0][1] = abs(N-R[1].x) + abs(N-R[1].y);
	for(i=0;i<=W;i++)
	{
		for(j=0;j<=W;j++)
		{
			if(i == j)	continue;
			if(i == 0 && j == 1)	continue;
			if(i == 1 && j == 0)	continue;
			
			int ch = 0;
			if(abs(i-j) != 1)
			{
				if(i < j)			ch += 1;
				int x = i + px[ch];
				int y = j + py[ch];
				if(ch % 2)
				{
					dp2[i][j] = y;
					if(y == 0)		dp[i][j] = dp[x][y] + abs(N - R[j].x) + abs(N - R[j].y);
					else			dp[i][j] = dp[x][y] + dis[y][j];
				}
				else
				{
					dp2[i][j] = x;
					dp[i][j] = dp[x][y] + dis[x][i];
				}
			}
			else
			{
				dp[i][j] = 1000000000;
				if(i < j)			ch += 1;
				for(k=2;;k++)
				{
					int x = i + k * px[ch];
					int y = j + k * py[ch];
					if(x < 0 || y < 0)	break;
					if(ch % 2)
					{
						dp2[i][j] = y;
						if(y == 0)
						{
							if(dp[i][j] > dp[x][y] + abs(N-R[j].x) + abs(N - R[j].y))
							dp[i][j] = dp[x][y] + abs(N-R[j].x) + abs(N-R[j].y);
						}
						else
						{
							if(dp[i][j] > dp[x][y] + dis[y][j])
							dp[i][j] = dp[x][y] + dis[y][j];
						}
					}
					else
					{
						dp2[i][j] = x;
						if(y == 0)
						if(dp[i][j] > dp[x][y] + dis[x][i])
						dp[i][j] = dp[x][y] + dis[x][i];
					}
				}
			}
		}
	}

	for(i=0;i<=W;i++)
	{
		for(j=0;j<=W;j++)
			printf("%d ", dp[i][j]);
		printf("\n");
	}
	printf("\n");

	int x, y;
	int ans = 100000000;
	for(i=0;i<W;i++)
	{
		if(dp[W][i] < ans)
		{
			x = W;
			y = i;
			ans = dp[W][i];
		}
		if(dp[i][W] < ans)
		{
			x = i;
			y = W;
			ans = dp[i][W];
		}
	}

	printf("%d\n", ans);

	while(x != 0 && y != 0)
	{
		if(x < y)
		{
			printf("2\n");
			y = dp2[x][y];
		}
		if(x > y)
		{
			printf("1\n");
			x = dp2[x][y];
		}
	}

	return 0;
}
