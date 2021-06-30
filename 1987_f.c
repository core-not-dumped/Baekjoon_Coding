#include <stdio.h>

char map[21][21];
int R, C;
int mapcheck[21][21];

void DFS(int r, int c, char Alpha[], int num)
{
	int i, j;
	int plusr[4] = {1,-1,0,0};
	int plusc[4] = {0,0,1,-1};

	int newr, newc;
	for(i=0;i<4;i++)
	{
		newr = r+plusr[i];
		newc = c+plusc[i];
		if(newr < 0 || newr >= R)	continue;
		if(newc < 0 || newc >= C)	continue;

		if(mapcheck[newr][newc] == 0)
		{
			for(j=0;j<num;j++)
			{
				if(map[newr][newc] == Alpha[j])	break;
			}
			if(j==num)
			{
				mapcheck[newr][newc] = mapcheck[r][c] + 1;
				Alpha[num] = map[newr][newc];
				num++;
				DFS(newr, newc, Alpha, num);
			}
		}
	}
}

int main(void)
{
	scanf("%d %d", &R, &C);

	int i, j;
	for(i=0;i<R;i++)
	{
		scanf("%s", map[i]);
	}

	char Al[30];
	int num = 1;
	mapcheck[0][0] = 1;
	Al[0] = map[0][0];
	DFS(0,0,Al,num);

	int max = 0;
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			if(mapcheck[i][j] > max)
				max = mapcheck[i][j];
		}
	}

	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			printf("%d ", mapcheck[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	printf("%d\n", max);

	return 0;
}
