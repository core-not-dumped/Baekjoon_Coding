#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

int qH[101];
int qV[101];
int map[10][10];
int ch[101][11];
int ind;
int check;

void pmap()
{
	int i, j;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
			printf("%d ", map[i][j]);
		printf("\n");
	}
	printf("\n");
}

void back(int N)
{
	if (N == ind)	{	check = 1;	return;	}
	
	int H = qH[N];
	int V = qV[N];
	int i, j;
	int h = H/3*3;
	int v = V/3*3;
	memset(ch[N],0,sizeof(int)*11);
	for(i=0;i<9;i++)	ch[N][map[H][i]] = 1;
	for(i=0;i<9;i++)	ch[N][map[i][V]] = 1;
	for(i=h;i<h+3;i++)
	{
		for(j=v;j<v+3;j++)
			ch[N][map[i][j]] = 1;
	}

	for(i=1;i<10;i++)
	{
		if(!ch[N][i])
		{
			map[H][V] = i;
			back(N+1);
			if(check == 1)	return;
			map[H][V] = 0;
		}
	}
}

int main(void)
{
	int i, j;
	ind = 0;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			scanf("%d", &map[i][j]);
			if(!map[i][j])
			{
				qH[ind] = i;
				qV[ind] = j;
				ind++;
			}
		}
	}

	check = 0;
	back(0);
	pmap();

	return 0;
}
