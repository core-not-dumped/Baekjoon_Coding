#include <stdio.h>

int main(void)
{
	int T, t;
	scanf("%d", &T);
	for(t=0;t<T;t++)
	{
		int map[15][15];
		int n,k;
		scanf("%d %d", &k, &n);
		int i,j;
		for(i=1;i<n+1;i++)	map[0][i] = i;
		for(i=1;i<k+1;i++)	map[i][1] = 1;
		for(i=1;i<k+1;i++)
		{
			for(j=2;j<n+1;j++)
				map[i][j] = map[i-1][j] + map[i][j-1];
		}
		printf("%d\n", map[k][n]);
	}

	return 0;
}
