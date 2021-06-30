#include <stdio.h>

struct virus{
	int x, y;
}v[10];

typedef struct QUE{
	int x, y;
}que;

que q[3000];

int N, M;
int ch[10] = {0,};
int map[51][51] = {0, };
int vidx = 0;
int nothing;
int min;

int BFS(void)
{
	int i, j;
	int maptmp[51][51];
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
			maptmp[i][j] = map[i][j];
	}

	int px[4] = {-1,0,1,0};
	int py[4] = {0,-1,0,1};
	int r = 0, f = 0;
	int nothing_tmp = nothing;

	for(i=0;i<vidx;i++)
	{
		if(ch[i])
		{
			maptmp[v[i].x][v[i].y] = 3;
			q[f++] = (que) {v[i].x, v[i].y};
		}
	}
	while(r<f)
	{
		for(i=0;i<4;i++)
		{
			int x = q[r].x + px[i];
			int y = q[r].y + py[i];
			if(x < 0 || x >= N)		continue;
			if(y < 0 || y >= N)		continue;
			if(maptmp[x][y] == 1)	continue;
			if(maptmp[x][y] == 0 || maptmp[x][y] == 2)
			{
				if(maptmp[x][y] == 0)	nothing_tmp--;
				maptmp[x][y] = maptmp[q[r].x][q[r].y]+1;
				q[f++] = (que) {x, y};
				if(nothing_tmp == 0)
				{
					/*int k;
					for(j=0;j<N;j++)
					{
						for(k=0;k<N;k++)
							printf("%d ", maptmp[j][k]);
						printf("\n");
					}
					printf("\n");*/
					return maptmp[x][y] - 3;
				}
			}
		}
		r++;
	}

	return -1;
}

void DFS(int idx, int act)
{
	if(act == M)
	{
		int t = BFS();
		if(t != -1)
		{
			if(t < min)	min = t;
		}
		return;
	}
	if(idx >= vidx)	return;

	ch[idx] = 1;
	DFS(idx+1, act+1);
	ch[idx] = 0;
	DFS(idx+1, act);
}

int main(void)
{
	scanf("%d %d", &N, &M);

	int i, j;
	nothing = N * N;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			scanf("%d", &map[i][j]);
			if(map[i][j] == 2)
			{
				v[vidx++] = (struct virus) {i, j};
				nothing--;
			}
			if(map[i][j] == 1)	nothing--;
		}
	}
	
	if(nothing == 0)
	{
		printf("0\n");
		return 0;
	}

	min = 999999999;
	DFS(0, 0);

	if(min == 999999999)	printf("-1\n");
	else					printf("%d\n", min);

	return 0;
}
