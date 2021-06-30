//15:7

#include <stdio.h>

struct MAP{
	int speed, dir, size;
};

struct MAP map[102][102] = {0,};
int R, C, M;

void print_map(void)
{
	int i, j;
	for(i=1;i<=R;i++)
	{
		for(j=1;j<=C;j++)
		printf("%d ", map[i][j].size);
		printf("\n");
	}
	printf("\n");
}

int main(void)
{
	int i, j, k;
	scanf("%d %d %d", &R, &C, &M);
	
	for(i=0;i<M;i++)
	{
		int r, c;
		scanf("%d %d", &r, &c);

		scanf("%d", &map[r][c].speed);
		scanf("%d", &map[r][c].dir);
		scanf("%d", &map[r][c].size);

		if(map[r][c].dir == 1 || map[r][c].dir == 2)
		map[r][c].speed = map[r][c].speed % (2*R - 2);
		if(map[r][c].dir == 3 || map[r][c].dir == 4)
		map[r][c].speed = map[r][c].speed % (2*C - 2);
	}

	int time = 1;
	int ans = 0;
	while(time <= C)
	{
		//1
		for(i=1;i<=R;i++)
		{
			if(map[i][time].size)
			{
				ans += map[i][time].size;

				map[i][time].speed = 0;
				map[i][time].dir = 0;
				map[i][time].size = 0;
				break;
			}
		}

		//2
		struct MAP maptmp[102][102] = {0,};
		int px[5] = {0,-1,1,0,0};
		int py[5] = {0,0,0,1,-1};
		for(i=1;i<=R;i++)
		{
			for(j=1;j<=C;j++)
			{
				if(map[i][j].size)
				{
					int x = i;
					int y = j;
					for(k=0;k<map[i][j].speed;k++)
					{
						x += px[map[i][j].dir];
						y += py[map[i][j].dir];
						if(map[i][j].dir == 1 && (x < 1 || x > R))
						{
							map[i][j].dir = 2;
							x += px[map[i][j].dir] * 2;
						}
						else if(map[i][j].dir == 2 && (x < 1 || x > R))
						{
							map[i][j].dir = 1;
							x += px[map[i][j].dir] * 2;
						}
						else if(map[i][j].dir == 3 && (y < 1 || y > C))
						{
							map[i][j].dir = 4;
							y += py[map[i][j].dir] * 2;
						}
						else if(map[i][j].dir == 4 && (y < 1 || y > C))
						{
							map[i][j].dir = 3;
							y += py[map[i][j].dir] * 2;
						}
					}
					if(maptmp[x][y].size < map[i][j].size)
					maptmp[x][y] = map[i][j];
				}
			}
		}
		
		for(i=1;i<=R;i++)
		{
			for(j=1;j<=C;j++)
				map[i][j] = maptmp[i][j];
		}
		
		time++;
	}

	printf("%d\n", ans);

	return 0;
}
