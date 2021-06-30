#include <stdio.h>

int D_dir(int d)
{
	if(d == 3)	return 0;
	else		return d + 1;
}

int L_dir(int d)
{
	if(d == 0)	return 3;
	else		return d - 1;
}

int q[20000][2];
int r, f;

int main(void)
{
	int N, K, L, i, j;
	scanf("%d", &N);
	scanf("%d", &K);

	int map[101][101];
	for(i=1;i<=N;i++)
	{
		for(j=1;j<=N;j++)
			map[i][j] = 0;
	}
	map[1][1] = 2;

	for(i=0;i<K;i++)
	{
		int H, V;
		scanf("%d %d", &H, &V);
		map[V][H] = 1;
	}

	int time[101];
	char dir[101];
	scanf("%d", &L);
	for(i=0;i<L;i++)
		scanf("%d %c", &time[i], &dir[i]);

	int direction = 0;
	int head[2] = {1,1};
	int tail[2] = {1,1};
	int time_idx = 0;
	int px[4] = {1,0,-1,0};
	int py[4] = {0,1,0,-1};
	r = 0, f = 0;
	q[0][0] = 1;
	q[0][1] = 1;
	for(i=0;;i++)
	{
		if(i == time[time_idx])
		{
			if(dir[time_idx] == 'D')	direction = D_dir(direction);
			else						direction = L_dir(direction);
			time_idx++;
		}
		int apple = 0;

		head[0] += px[direction];
		head[1] += py[direction];
		q[++f][0] = head[0];
		q[f][1] = head[1];

		if(map[head[0]][head[1]] >= 2)
		{
			printf("%d\n", i + 1);
			return 0;
		}
		if(head[0] <= 0 || head[0] > N || head[1] <= 0 || head[1] > N )
		{
			printf("%d\n", i + 1);
			return 0;
		}
		if(map[head[0]][head[1]] == 1)	apple = 1;
		map[head[0]][head[1]] = 2;
		if(!apple)
		{
			map[tail[0]][tail[1]] = 0;
			tail[0] = q[++r][0];
			tail[1] = q[r][1];
		}
	}
}
