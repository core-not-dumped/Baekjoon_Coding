#include <stdio.h>

#define min(a,b) a<b?a:b
#define MAX 20000000

int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);

	int i, j, k;
	int map[101][101];
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i == j)	map[i][j] = 0;
			else		map[i][j] = MAX;
		}
	}

	for(i=0;i<m;i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if(map[a][b] > c)
		map[a][b] = c;
	}

	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
		}
	}

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(map[i][j] == MAX)
			printf("0 ");
			else
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	return 0;
}
