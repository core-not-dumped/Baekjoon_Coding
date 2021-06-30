#include <stdio.h>

typedef struct _que {
	int x, y, r;
}Que;

Que que[100];
int N, M, D;
short map[15][15];
int def[3];
int max;

void BFS(void)
{
	short maptmp[15][15];
	short visit[15][15][3];
	int i, j, k;
	for(i=0;i<15;i++)
	{
		for(j=0;j<15;j++)
		{
			for(k=0;k<3;k++)	visit[i][j][k] = 0;
			maptmp[i][j] = map[i][j];
		}
	}

	Que enemy[3];
	int ch[3] = {0, 0, 0};
	int visitch;
	int remove = 0;
	int r, f, x, y;
	int px[3] = {-1,0,1};
	int py[3] = {0,-1,0};
	for(k = N-1;k >= 0;k--)
	{
		ch[0] = ch[1] = ch[2] = 0;
		for(i=0;i<3;i++)
		{
			if(maptmp[k][def[i]])
			{
				ch[i] = 1;
				enemy[i] = (Que){def[i], k, 1};
				continue;
			}

			visitch = (1 << k);
			que[0] = (Que){def[i], k, 1};
			visit[k][def[i]][i] |= visitch;
			r = 0;
			f = 1;
			while(r<f)
			{
				if(que[r].r == D)	break;
				for(j=0;j<3;j++)
				{
					x = px[j] + que[r].x;
					y = py[j] + que[r].y;
					if(x < 0 || x >= M)	continue;
					if(y < 0 || y >= N)	continue;
					if(!maptmp[y][x])
					{
						if(!(visit[y][x][i] & visitch))
						{
							visit[y][x][i] |= visitch;
							que[f] = (Que){x, y, que[r].r + 1};
							f++;
						}
					}
					else
					{
						enemy[i] = (Que){x, y, que[r].r + 1};
						ch[i] = 1;
						goto EXIT;
					}
				}
				r++;
			}
			EXIT:	continue;
		}
		for(i=0;i<3;i++)
		{
			if(!ch[i])	continue;
			if(maptmp[enemy[i].y][enemy[i].x])
			{
				maptmp[enemy[i].y][enemy[i].x] = 0;
				remove++;
			}
		}
	}

	if(remove > max)	max = remove;
}

void B(int a, int num)
{
	if(num == 3)	{ BFS();	return; }
	if(a == M)	return;

	def[num] = a;
	B(a + 1, num + 1);
	def[num] = 0;
	B(a + 1, num);
}

int main(void)
{
	scanf("%d %d %d", &N, &M, &D);

	int i, j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
			scanf("%d", &map[i][j]);
	}

	max = 0;
	B(0, 0);

	printf("%d\n", max);

	return 0;
}
