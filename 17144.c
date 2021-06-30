#include <stdio.h>

int map[50][50];
int R, C, T;

int main(void)
{
	scanf("%d %d %d", &R, &C, &T);

	int i, j, k;
	int ma[2];
	int ma_idx = 0;
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			scanf("%d", &map[i][j]);
			if(map[i][j] == -1)
				ma[ma_idx++] = i;
		}
	}

	int recent_time = 0;
	int px[4] = {-1,0,1,0};
	int py[4] = {0,-1,0,1};
	while(recent_time < T)
	{
		int maptmp[51][51];
		for(i=0;i<R;i++)
		{
			for(j=0;j<C;j++)
				maptmp[i][j] = 0;
		}
		maptmp[ma[0]][0] = -1;
		maptmp[ma[1]][0] = -1;

		// 1
		for(i=0;i<R;i++)
		{
			for(j=0;j<C;j++)
			{
				if(map[i][j] != 0 && map[i][j] != -1)
				{
					int sum = 0;
					for(k=0;k<4;k++)
					{
						int x = i + px[k];
						int y = j + py[k];
						if(x < 0 || x >= R)	continue;
						if(y < 0 || y >= C)	continue;
						if(map[x][y] == -1)	continue;
						maptmp[x][y] += map[i][j] / 5;
						sum += map[i][j] / 5;
					}
					maptmp[i][j] += map[i][j] - sum;
				}
			}
		}

		for(i=0;i<R;i++)
		{
			for(j=0;j<C;j++)
				map[i][j] = maptmp[i][j];
		}

		// 2
		for(i=ma[0]-1;i>0;i--)	map[i][0] = map[i-1][0];
		for(i=0;i<C-1;i++)		map[0][i] = map[0][i+1];
		for(i=0;i<ma[0];i++)	map[i][C-1] = map[i+1][C-1];
		for(i=C-1;i>=2;i--)		map[ma[0]][i] = map[ma[0]][i-1];
		map[ma[0]][1] = 0;

		for(i=ma[1]+1;i<R-1;i++)	map[i][0] = map[i+1][0];
		for(i=0;i<C-1;i++)			map[R-1][i] = map[R-1][i+1];
		for(i=R-1;i>ma[1];i--)		map[i][C-1] = map[i-1][C-1];
		for(i=C-1;i>=2;i--)			map[ma[1]][i] = map[ma[1]][i-1];
		map[ma[1]][1] = 0;

		recent_time++;
	}

	int ans = 0;
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
			ans += map[i][j];
	}
	printf("%d\n", ans + 2);

	return 0;
}
