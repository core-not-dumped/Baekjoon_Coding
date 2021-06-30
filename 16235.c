#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);

	int i, j, k, l;
	int map[10][10];
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
			map[i][j] = 5;
	}

	int A[10][10];
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
			scanf("%d", &A[i][j]);
	}

	int tree_r[10][10] = {0,};
	int tree_f[10][10] = {0,};
	int tree[10][10][10000] = {0,};
	for(i=0;i<M;i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		scanf("%d", &tree[x-1][y-1][0]);
		tree_f[x-1][y-1]++;
	}

	int px[8] = {-1,-1,-1,0,0,1,1,1};
	int py[8] = {-1,0,1,-1,1,-1,0,1};
	int year = 0;
	while(year < K)
	{
		//spring
		int death_tree[10][10] = {0, };
		for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
			{
				for(k=tree_f[i][j]-1;k>=tree_r[i][j];k--)
				{
					if(map[i][j] >= tree[i][j][k])
					{
						map[i][j] -= tree[i][j][k];
						tree[i][j][k]++;
					}
					else	break;
				}

				for(l=k;l>=tree_r[i][j];l--)
					map[i][j] += tree[i][j][l]/2;
				tree_r[i][j] = k+1;
			}
		}

		//fall
		for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
			{
				for(k=tree_r[i][j];k<tree_f[i][j];k++)
				{
					if(tree[i][j][k] % 5 == 0)
					{
						for(l=0;l<8;l++)
						{
							int x = i + px[l];
							int y = j + py[l];
							if(x < 0 || x >= N)	continue;
							if(y < 0 || y >= N)	continue;
							tree[x][y][tree_f[x][y]++] = 1;
						}
					}
				}
			}
		}

		//winter
		for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
			map[i][j] += A[i][j];
		}
		year++;
	}

	int ans = 0;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
			ans += tree_f[i][j] - tree_r[i][j];
	}

	printf("%d\n", ans);

	return 0;
}
