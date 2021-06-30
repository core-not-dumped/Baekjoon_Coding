#include <stdio.h>

int N, M, c, max;
int map[8][8], d[10];

struct CCTV{
	int x, y, k;
}cctv[10];

int fill(void)
{
	int p[5][4][4] =   {{{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}},
						{{1,0,1,0},{0,1,0,1},{0,0,0,0},{0,0,0,0}},
						{{1,1,0,0},{0,1,1,0},{0,0,1,1},{1,0,0,1}},
						{{1,1,1,0},{0,1,1,1},{1,0,1,1},{1,1,0,1}},
						{{1,1,1,1},{0,0,0,0},{0,0,0,0},{0,0,0,0}}};
	int px[4] = {0,1,0,-1};
	int py[4] = {-1,0,1,0};

	int maptmp[8][8];
	int i, j, k;
	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
			maptmp[i][j] = map[i][j];
	}

	int cnt = 0;
	for(i=0;i<c;i++)
	{
		for(j=0;j<4;j++)
		{
			if(p[cctv[i].k][d[i]][j])
			{
				int x = cctv[i].x;
				int y = cctv[i].y;
				for(k=1;;k++)
				{
					x += px[j];
					y += py[j];
					if(x < 0 || x >= N)	break;
					if(y < 0 || y >= M)	break;
					if(maptmp[x][y] == 0)
					{
						maptmp[x][y] = 7;
						cnt++;
					}
					else if(maptmp[x][y] <= 5)	continue;
					else if(maptmp[x][y] == 7)	continue;
					else	break;
				}
			}
		}
	}

	return cnt;
}

void DFS(int n)
{
	if(n == c)
	{
		int f = fill();
		if(max < f)	max = f;
		return;
	}
	
	int fin, i;
	if(cctv[n].k == 1)	fin = 2;
	else if(cctv[n].k == 4)	fin = 1;
	else	fin = 4;
	for(i=0;i<fin;i++)
	{
		d[n] = i;
		DFS(n + 1);
	}
}

int main(void)
{
	scanf("%d %d", &N, &M);

	int i, j, wall = 0;
	c = 0;
	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
		{
			scanf("%d", &map[i][j]);
			if(map[i][j] == 6)	wall++;
			else if(map[i][j])
			{
				cctv[c] = (struct CCTV){i,j,map[i][j]-1};
				c++;
			}
		}
	}

	max = 0;
	DFS(0);

	printf("%d\n", N*M - c - max - wall);

	return 0;
}
