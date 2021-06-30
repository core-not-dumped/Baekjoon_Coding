#include <stdio.h>

struct p{
	int x, y;
}q[2500];

int main(void)
{
	int t;
	scanf("%d", &t);

	while(t--)
	{
		int M, N, K;
		scanf("%d %d %d", &M, &N, &K);

		int map[50][50] = {0};
		int i, j;
		for(i=0;i<K;i++)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			map[x][y] = 1;
		}

		int num = 1;
		for(i=0;i<M;i++)
		{
			for(j=0;j<N;j++)
			{
				if(map[i][j] != 1)	continue;
		
				num++;
				q[0] = (struct p){i, j};
				int r = 0, f = 1;
				int px[4] = {1,0,-1,0};
				int py[4] = {0,1,0,-1};
				while(r < f)
				{
					int k;
					for(k=0;k<4;k++)
					{
						int x = px[k] + q[r].x;
						int y = py[k] + q[r].y;
						if(x >= M || x < 0)	continue;
						if(y >= N || y < 0)	continue;
						if(map[x][y] == 1)
						{
							q[f++] = (struct p){x, y};
							map[x][y] = num;
						}
					}
					r++;
				}
			}
		}
		printf("%d\n", num-1);
	}

	return 0;
}
