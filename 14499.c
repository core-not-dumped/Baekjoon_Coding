#include <stdio.h>

int main(void)
{
	int N, M;
	scanf("%d %d", &N, &M);

	int x, y;
	scanf("%d %d", &x, &y);

	int K;
	scanf("%d", &K);

	int map[20][20];
	int i, j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
			scanf("%d", &map[i][j]);
	}

	int dice[6] = {0,0,0,0,0,0};
	int next[4][6] = {{2,1,5,0,4,3},
					  {3,1,0,5,4,2},
					  {1,5,2,3,0,4},
					  {4,0,2,3,5,1}};

	int px[4] = {0,0,-1,1};
	int py[4] = {1,-1,0,0};

	for(i=0;i<K;i++)
	{
		int dice_tmp[6];
		int dir;
		scanf("%d", &dir);

		x += px[dir-1];
		y += py[dir-1];

		if(x >= N || x < 0 || y < 0 || y >= M)
		{
			x -= px[dir-1];
			y -= py[dir-1];
			continue;
		}

		for(j=0;j<6;j++)
			dice_tmp[j] = dice[next[dir-1][j]];
		for(j=0;j<6;j++)
			dice[j] = dice_tmp[j];

		if(map[x][y] == 0)
			map[x][y] = dice[5];
		else
		{
			dice[5] = map[x][y];
			map[x][y] = 0;
		}
		printf("%d\n", dice[0]);
	}

	return 0;
}
