#include <stdio.h>

int main(void)
{
	int N;
	scanf("%d", &N);

	int M;
	scanf("%d", &M);

	int i, j;
	int map[101][101];
	for(i=0;i<=N;i++)
	{
		for(j=0;j<=N;j++)
			map[i][j] = 0;
	}

	for(i=0;i<M;i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		map[x][y] = 1;
		map[y][x] = 1;
	}

	int ch[101] = {0,1,};
	int q[101] = {1,};
	int r=0, f=1;
	while(r < f)
	{
		for(i=2;i<=N;i++)
		{
			if(map[i][q[r]] && !ch[i])
			{
				ch[i] = 1;
				q[f++] = i;
			}
		}
		r++;
	}

	printf("%d\n", f-1);

	return 0;
}
