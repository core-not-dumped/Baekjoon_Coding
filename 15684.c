#include <stdio.h>
#include <stdlib.h>

int N, M, H, lad[15][35];

void check(int n)
{
	int x, y, i;
	for(i=1;i<=N;i++)
	{
		y = 1;
		x = i;
		while(y <= H)
		{
			if(lad[x][y])			x++;
			else if(lad[x-1][y])	x--;
			y++;
		}
		if(x != i)	return;
	}

	printf("%d\n", n);
	exit(0);
}

void dfs(int x, int y, int n, int ch)
{
	if(ch == n)	{	check(n);	return;	}

	do{
		x = (y == H) ? x+1 : x;
		y = y%H + 1;
		if(x > N)	return;
	} while(lad[x][y] || lad[x-1][y] || lad[x+1][y]);

	lad[x][y] = 1;
	dfs(x,y,n,ch+1);

	lad[x][y] = 0;
	while(!lad[x][y+2] && !lad[x+1][y+1] && !lad[x-1][y+1])
	{
		if(y+2 > H)	break;
		y++;
	}
	dfs(x,y,n,ch);
}

int main(void)
{
	scanf("%d %d %d", &N, &M, &H);

	int i, j, ls, lg;
	for(i=0;i<M;i++)
	{
		scanf("%d %d", &ls, &lg);
		lad[lg][ls] = 1;
	}

	for(i=0;i<4;i++)	dfs(1,0,i,0);
	printf("-1\n");

	return 0;
}
