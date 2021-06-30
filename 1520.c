#include <stdio.h>
#include <memory.h>

int map[501][501];
int dp[501][501];
int M, N;

int dfs(int x, int y)
{
	if(x == (M-1) && y == (N-1))	return 1;
	if(dp[x][y] != -1)				return dp[x][y];

	dp[x][y] = 0;
	int px[4] = {0,1,0,-1};
	int py[4] = {1,0,-1,0};
	int i, nx, ny;

	for(i=0;i<4;i++)
	{
		nx = px[i] + x;
		ny = py[i] + y;
		if(nx >= M || nx < 0)	continue;
		if(ny >= N || ny < 0)	continue;
		if(map[x][y] > map[nx][ny])	dp[x][y] += dfs(nx,ny);
	}

	return dp[x][y];
}

int main(void)
{
	scanf("%d %d", &M, &N);

	int i, j;
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
			scanf("%d", &map[i][j]);
	}

	for(i=0;i<M;i++)
		memset(dp[i],-1,sizeof(dp[i]));

	printf("%d\n", dfs(0,0));

	return 0;
}
