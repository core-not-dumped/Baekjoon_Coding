#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b)
{
	return *(int*)a > *(int*)b;
}

int map[27][27];
int ans[313];
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

int dfs(int x, int y, int cnt)
{
	int i, tot = 1;
	map[x][y] = cnt+1;
	for(i=0;i<4;i++)
	{
		if(map[x+dx[i]][y+dy[i]] == 1)
		{
			tot += dfs(x+dx[i], y+dy[i], cnt);
		}
	}
	return tot;
}


int main()
{
	int n, i, j, cnt = 0;
	char str[26];
	scanf("%d", &n);
	for(i=1;i<=n;i++)
	{
		scanf("%s", str);
		for(j=1;j<=n;j++)
		{
			map[i][j] = str[j-1]-'0';
		}
	}

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(map[i][j] == 1)
			{
				ans[cnt] = dfs(i, j, cnt+1);
				cnt++;
			}
		}
	}
	qsort(ans, cnt, sizeof(int), cmp);
	
	printf("%d\n", cnt);
	for(i=0;i<cnt;i++)
	{
		printf("%d\n", ans[i]);
	}
	
	return 0;
}
