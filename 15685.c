#include <stdio.h>

int main(void)
{
	int N;
	scanf("%d", &N);

	int i, j;
	int curve[2000] = {0,};
	for(i=0;i<10;i++)
	{
		for(j=0;j<(1<<i);j++)
			curve[(1<<i) + j] = (1 + curve[(1<<i) - j - 1]) % 4;
	}

	int px[4] = {1,0,-1,0};
	int py[4] = {0,-1,0,1};
	int map[101][101];
	int x, y, d, g;

	for(i=0;i<=100;i++)
	{
		for(j=0;j<=100;j++)
			map[i][j] = 0;
	}

	for(i=0;i<N;i++)
	{
		scanf("%d %d %d %d", &x, &y, &d, &g);
		map[x][y]++;
		for(j=0;j<(1<<g);j++)
		{
			int direc = (d + curve[j]) % 4;
			x = x + px[direc];
			y = y + py[direc];
			map[x][y]++;
		}
	}

	int ans = 0;
	for(i=0;i<100;i++)
	{
		for(j=0;j<100;j++)
		{
			if(map[i][j] && map[i+1][j] && map[i][j+1] && map[i+1][j+1])
			ans++;
		}
	}

	printf("%d\n", ans);

	return 0;
}
