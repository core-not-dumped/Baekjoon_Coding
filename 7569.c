#include <stdio.h>

struct p{
	int x, y, z;
}q[1000000];

int main(void)
{
	int M, N, H;
	scanf("%d %d %d", &M, &N, &H);

	int map[100][100][100];
	int i, j, k;
	int num = 0;
	int wall = 0;
	for(i=0;i<H;i++)
	{
		for(j=0;j<N;j++)
		{
			for(k=0;k<M;k++)
			{
				scanf("%d", &map[k][j][i]);
				if(map[k][j][i] == 1)
					q[num++] = (struct p){k, j, i};
				if(map[k][j][i] == -1)
					wall++;
			}
		}
	}

	if(N*M*H == num + wall)
	{
		printf("0\n");
		return 0;
	}

	int px[6] = {1,0,-1,0,0,0};
	int py[6] = {0,1,0,-1,0,0};
	int pz[6] = {0,0,0,0,-1,1};
	int r = 0;
	while(r < num)
	{
		for(i=0;i<6;i++)
		{
			int x = q[r].x + px[i];
			int y = q[r].y + py[i];
			int z = q[r].z + pz[i];
			if(x >= M || x < 0)	continue;
			if(y >= N || y < 0)	continue;
			if(z >= H || z < 0)	continue;
			if(!map[x][y][z])
			{
				map[x][y][z] = map[q[r].x][q[r].y][q[r].z] + 1;
				q[num++] = (struct p){x, y, z};
				if(num == (N * M * H - wall))
				{
					printf("%d\n", map[x][y][z]-1);
					return 0;
				}
			}
		}
		r++;
	}

	printf("%d\n", -1);

	return 0;
}
