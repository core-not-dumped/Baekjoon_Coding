#include <stdio.h>

struct p{
	int x, y;
}q[1000000];

int main(void)
{
	int M, N;
	scanf("%d %d", &M, &N);

	int map[1000][1000];
	int i, j;
	int num = 0;
	int wall = 0;
	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
		{
			scanf("%d", &map[i][j]);
			if(map[i][j] == 1)
				q[num++] = (struct p){i, j};
			if(map[i][j] == -1)
				wall++;
		}
	}

	if(N*M == num + wall)
	{
		printf("0\n");
		return 0;
	}

	int px[4] = {1,0,-1,0};
	int py[4] = {0,1,0,-1};
	int r = 0;
	while(r < num)
	{
		for(i=0;i<4;i++)
		{
			int x = q[r].x + px[i];
			int y = q[r].y + py[i];
			if(x >= N || x < 0)	continue;
			if(y >= M || y < 0)	continue;
			if(!map[x][y])
			{
				map[x][y] = map[q[r].x][q[r].y] + 1;
				q[num++] = (struct p){x, y};
				if(num == (N * M - wall))
				{
					printf("%d\n", map[x][y]-1);
					return 0;
				}
			}
		}
		r++;
	}

	printf("%d\n", -1);

	return 0;
}
