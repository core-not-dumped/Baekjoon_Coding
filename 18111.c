#include <stdio.h>
#include <limits.h>

int main(void)
{
	int M, N, B;
	scanf("%d %d %d", &M, &N, &B);
	
	int block = B;
	int i, j;
	int map[500][500];
	int low = 256, high = 0;
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
			scanf("%d", &map[i][j]);
			block += map[i][j];
			if(low > map[i][j])		low = map[i][j];
			if(high < map[i][j])	high = map[i][j];
		}
	}
	
	
	int s, e;
	s = low;
	e = high < block/(N*M) ? high : block/(N*M);
	
	int min = INT_MAX;
	int height;
	int time;
	for(;s<=e;s++)
	{
		time = 0;
		for(i=0;i<M;i++)
		{
			for(j=0;j<N;j++)
			{
				if(map[i][j] > s)
					time += (map[i][j] - s) * 2;
				else if(map[i][j] < s)
					time += (s - map[i][j]);
			}
		}
		if(min >= time)
		{
			min = time;
			height = s;
		}
	}
	
	printf("%d %d\n", min, height);
	
	return 0;
}
