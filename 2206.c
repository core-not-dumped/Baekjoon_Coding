#include <stdio.h>

#define MAX 10000

typedef struct _que {
	int x, y, s;
}Que;

Que que[MAX];
int N, M;
int map[1000][1000][2];
int m[1000][1000];

int BFS(void)
{
	int i;
	int r, f, rc, fc;
	int x, y;
	int px[4] = {0,1,0,-1};
	int py[4] = {1,0,-1,0};
	Que q;
	f = 1;
	r = rc = fc = 0;

	if(m[0][0])
	{
		map[0][0][1]++;
		que[0] = (Que){0, 0, 1};
	}
	else
	{
		map[0][0][0]++;
		que[0] = (Que){0, 0, 0};
	}

	while(r<f || rc <= fc)
	{
		q = que[r];
		if(q.x == N-1 && q.y ==  M-1)	return map[q.x][q.y][q.s];

		for(i=0;i<4;i++)
		{
			x = px[i] + q.x;
			y = py[i] + q.y;
			if(x < 0 || x >= N)	continue;
			if(y < 0 || y >= M)	continue;
			if(m[x][y])
			{
				if(!q.s && (!map[x][y][1] || map[x][y][1] > map[q.x][q.y][0] + 1))
				{
					que[f].x = x;
					que[f].y = y;
					que[f].s = 1;
					map[x][y][1] = map[q.x][q.y][0] + 1;
					f++;
					if(f == MAX)	{fc++;	f = 0;}
				}
			}
			else
			{
				if((!map[x][y][q.s] || map[x][y][q.s] > map[q.x][q.y][q.s] + 1))
				{
					que[f].x = x;
					que[f].y = y;
					que[f].s = q.s;
					map[x][y][q.s] = map[q.x][q.y][q.s] + 1;
					f++;
					if(f == MAX)	{fc++;	f = 0;}
				}
			}
		}
		r++;
		if(r == MAX)	{rc++;	r = 0;}
	}
	
	return -1;
}

int main(void)
{
	int i, j;
	scanf("%d %d", &N, &M);

	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
			scanf("%1d", &m[i][j]);
	}

	printf("%d\n", BFS());

	return 0;
}
