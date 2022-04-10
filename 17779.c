#include <stdio.h>

int main(void)
{
	int N;
	scanf("%d", &N);
	
	int A[21][21];
	int i, j;
	for(i=1;i<=N;i++)
		for(j=1;j<=N;j++)
			scanf("%d", &A[i][j]);
	
	int result = 999999999;
	int x, y, d1, d2;
	for(x=1;x<=N;x++)
	{
		for(y=1;y<=N;y++)
		{
			for(d1=1;d1<=N;d1++)
			{
				for(d2=1;d2<=N;d2++)
				{
					if(x+d1+d2 > N)	continue;
					if(y-d1 < 1)	continue;
					if(y+d2 > N)	continue;
					
					int a[5] = {0,};
					for(i=1;i<=N;i++)
					{
						for(j=1;j<=N;j++)
						{
							if(i < x+d1 && j <= y && (i+j) < (x+y))					a[0] += A[i][j];
							else if(i <= x+d2 && j > y && (i-j) < (x-y))			a[1] += A[i][j];
							else if(i >= x+d1 && j < y-d1+d2 && (i-j) > (x-y+2*d1))	a[2] += A[i][j];
							else if(i > x+d2 && j >= y-d1+d2 && (i+j) > (x+y+2*d2))	a[3] += A[i][j];
							else												a[4] += A[i][j];
						}
					}
					
					int max = -1, min = 999999999;
					for(i=0;i<=4;i++)
					{
						if(max < a[i])	max = a[i];
						if(min > a[i])	min = a[i];
					}
					
					if(result > max - min)
						result = max - min;
				}
			}
		}
	}
	
	printf("%d\n", result);
	return 0;
}






