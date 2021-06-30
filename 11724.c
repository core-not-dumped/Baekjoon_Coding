#include<stdio.h>

int map[1001][1001];
int visit[1001];
int cnt;
int n, m;

void dfs(int idx)
{
	visit[idx] = 1;
	for(int k = 1; k <= n; k++)
	{
		if(!visit[k] && map[idx][k])
			dfs(k);
	}

}

int main()
{
	scanf("%d %d", &n, &m);
	int v1, v2;
	int i, j;
	for(i = 0; i < m; i++)
	{
		scanf("%d %d", &v1, &v2);
		map[v1][v2] = 1;
		map[v2][v1] = 1;
	}

	for(j = 1; j <= n; j++)
	{
		if (!visit[j])
		{
			dfs(j);
			cnt++;
		}
	}

	printf("%d\n", cnt);
	return 0;
}
