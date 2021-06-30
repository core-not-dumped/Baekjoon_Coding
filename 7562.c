#include <stdio.h>

struct que{
	int x, y;
}q[90000];

int main(void)
{
	int t;
	scanf("%d", &t);

	while(t--)
	{
		int I;
		scanf("%d", &I);
		int map[300][300] = {0};

		int sx, sy, ex, ey;
		scanf("%d %d", &sx, &sy);
		scanf("%d %d", &ex, &ey);

		if(sx == ex && sy == ey)
		{
			printf("0\n");
			goto next;
		}

		map[sx][sy] = 1;
		q[0] = (struct que){sx, sy};
		int px[8] = {1,2,2,1,-1,-2,-2,-1};
		int py[8] = {2,1,-1,-2,-2,-1,1,2};
		int r = 0, f = 1;
		int i;
		while(r < f)
		{
			for(i=0;i<8;i++)
			{
				int x = px[i] + q[r].x;
				int y = py[i] + q[r].y;
				if(x >= I || x < 0)	continue;
				if(y >= I || y < 0)	continue;
				if(!map[x][y])
				{
					map[x][y] = map[q[r].x][q[r].y] + 1;
					q[f++] = (struct que){x, y};
					if(x == ex && y == ey)
					{
						printf("%d\n", map[x][y] - 1);
						goto next;
					}
				}
			}
			r++;
		}

		next:
			continue;
	}

	return 0;
}
