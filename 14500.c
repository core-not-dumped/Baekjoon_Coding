#include <stdio.h>

int main(void)
{
	int N, M;
	scanf("%d %d", &N, &M);

	int i, j;
	int map[500][500];
	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
			scanf("%d", &map[i][j]);
	}

	int t_x[6][4][4] = {
							{{0,1,2,3},
							{0,0,0,0},
							{0,0,0,0},
							{0,0,0,0}},
					
							{{0,1,0,1},
							{0,0,0,0},
							{0,0,0,0},
							{0,0,0,0}},

							{{0,0,0,1},
							{0,1,2,2},
							{0,0,0,-1},
							{0,-1,-2,-2}},
							
							{{0,0,1,1},
							{0,1,1,2},
							{0,0,-1,-1},
							{0,1,1,2}},

							{{0,1,2,1},
							{0,0,0,1},
							{0,-1,-2,-1},
							{0,0,0,-1}},
		
							{{0,0,0,-1},
							{0,1,2,2},
							{0,0,0,1},
							{0,-1,-2,-2}}
						};

	int t_y[6][4][4] = {
							{{0,0,0,0},
							{0,1,2,3},
							{0,0,0,0},
							{0,0,0,0}},
			
							{{0,0,1,1},
							{0,0,0,0},
							{0,0,0,0},
							{0,0,0,0}},
			
							{{0,1,2,2},
							{0,0,0,-1},
							{0,-1,-2,-2},
							{0,0,0,1}},
		
							{{0,1,1,2},
							{0,0,-1,-1},
							{0,1,1,2},
							{0,0,1,1}},
	
							{{0,0,0,1},
							{0,-1,-2,-1},
							{0,0,0,-1},
							{0,1,2,1}},

							{{0,1,2,2},
							{0,0,0,1},
							{0,-1,-2,-2},
							{0,0,0,-1}}
						};

	int kind, dir, idx, max = 0;
	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
		{
			for(kind=0;kind<6;kind++)
			{
				for(dir=0;dir<4;dir++)
				{
					if(kind == 0 && dir == 2)	break;
					if(kind == 1 && dir == 1)	break;
					int sum = 0;
					for(idx=0;idx<4;idx++)
					{
						int x = i + t_x[kind][dir][idx];
						int y = j + t_y[kind][dir][idx];
						if(x < 0 || x >= N)	break;
						if(y < 0 || y >= M)	break;
						sum += map[x][y];
					}
					if(idx == 4 && sum > max)	max = sum;
				}
			}
		}
	}

	printf("%d\n", max);

	return 0;
}
