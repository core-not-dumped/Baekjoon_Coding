#include <stdio.h>

int N, M, r, c, d;
int map[51][51];

void left(void)
{
	if(d == 0)	d = 3;
	else	d--;
}

int main(void)
{
	// north 0, east 1, south 2, west 3
	scanf("%d %d", &N, &M);
	scanf("%d %d %d", &r, &c, &d);

	int i,j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
			scanf("%d", &map[i][j]);
	}

	int clean = 0;
	int r_plus[5] = {-1,0,1,0};
	int c_plus[5] = {0,1,0,-1};
	int r_update;
	int c_update;

	while(1)
	{
		if(map[r][c] == 0)
		{
			map[r][c] = 2;
			clean++;
		}

		for(i=0;i<4;i++)
		{
			left();
			r_update = r+r_plus[d];
			c_update = c+c_plus[d];

			if(map[r_update][c_update] == 0)
			{
				r = r_update;
				c = c_update;
				break;
			}
		}

		if(i == 4)
		{
			r_update = r-r_plus[d];
			c_update = c-c_plus[d];

			if(map[r_update][c_update] == 1)
			{
				printf("%d\n", clean);
				return 0;
			}
			else
			{
				r = r_update;
				c = c_update;
			}
		}
	}

	return 0;
}
