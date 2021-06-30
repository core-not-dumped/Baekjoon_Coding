//20:50

#include <stdio.h>
#include <stdlib.h>

struct home{
	int x, y;
}h[100];

struct chicken{
	int x, y;
}c[13];

int N, M, min;
int hidx, cidx;
int ch[13];
int map[51][51];

int LEN(void)
{
	int i, j;
	int len = 0;
	for(i=0;i<hidx;i++)
	{
		int c_len = 999999999;
		for(j=0;j<cidx;j++)
		{
			int lentmp = 0;
			if(ch[j])
			{
				lentmp += abs(c[j].x - h[i].x);
				lentmp += abs(c[j].y - h[i].y);
				if(c_len > lentmp)	c_len = lentmp;
			}
		}
		len += c_len;
	}
	return len;
}

void DFS(int idx, int select)
{
	if(select == M)
	{
		int len = LEN();
		if(len < min)	min = len;
		return;
	}
	if(idx >= cidx)	return;
	ch[idx] = 1;
	DFS(idx + 1, select + 1);
	ch[idx] = 0;
	DFS(idx + 1, select);
}

int main(void)
{
	scanf("%d %d", &N, &M);

	int i, j;
	hidx = 0;
	cidx = 0;
	for(i=1;i<=N;i++)
	{
		for(j=1;j<=N;j++)
		{
			scanf("%d", &map[i][j]);
			if(map[i][j] == 1)
				h[hidx++] = (struct home) {i, j};
			if(map[i][j] == 2)
				c[cidx++] = (struct chicken) {i, j};
		}
	}

	for(i=0;i<13;i++)	ch[i] = 0;
	min = 999999999;
	DFS(0, 0);
	printf("%d\n", min);

	return 0;
}
