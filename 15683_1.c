#include <stdio.h>

int N, M, c, min, cnt;
int map[8][8];
int p[5][4][4] =   {{{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}},
					{{1,0,1,0},{0,1,0,1},{0,0,0,0},{0,0,0,0}},
					{{1,1,0,0},{0,1,1,0},{0,0,1,1},{1,0,0,1}},
					{{1,1,1,0},{0,1,1,1},{1,0,1,1},{1,1,0,1}},
					{{1,1,1,1},{0,0,0,0},{0,0,0,0},{0,0,0,0}}};
int px[4] = {0,1,0,-1};
int py[4] = {-1,0,1,0};

struct CCTV{
	int x, y, k;
}cctv[10];

void ch(int n, int i, int mp)
{
	int j, k;
	for(j=0;j<4;j++)
	{
		if(p[cctv[n].k][i][j])
		{
			int x = cctv[n].x;
			int y = cctv[n].y;
			for(k=1;;k++)
			{
				x += px[j];
				y += py[j];
				if(x < 0 || x >= N)	break;
				if(y < 0 || y >= M)	break;
				if(map[x][y] == 0 && mp == 8)
				{
					map[x][y] += mp;
					cnt--;
				}
				else if(map[x][y] == 8 && mp == -8)
				{
					map[x][y] += mp;
					cnt++;
				}
				else if(map[x][y] % 8 == 0)	map[x][y] += mp;
				else if(map[x][y] <= 5)	continue;
				else	break;
			}
		}
	}
}

void DFS(int n)
{
	if(n == c)
	{
		if(min > cnt)	min = cnt;
		return;
	}
	
	int fin[5] = {4,2,4,4,1}, i;
	for(i=0;i<fin[cctv[n].k];i++)
	{
		ch(n,i,8);
		DFS(n + 1);
		ch(n,i,-8);
	}
}

int main(void)
{
	scanf("%d %d", &N, &M);

	int i, j;
	cnt = N*M;
	c = 0;
	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
		{
			scanf("%d", &map[i][j]);
			if(map[i][j] == 6)	cnt--;
			else if(map[i][j])
			{
				cctv[c] = (struct CCTV){i,j,map[i][j]-1};
				cnt--;
				c++;
			}
		}
	}

	min = 99;
	DFS(0);

	printf("%d\n", min);

	return 0;
}
