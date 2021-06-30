#include <stdio.h>

#define INF 99999999

int w[17][17];
int ca[16][1<<16];
int N;

int dp(int f, int visit)
{
	if((1<<f) == visit)
		return w[0][f] ? w[0][f] : INF;

	if(ca[f][visit] != 0)
		return ca[f][visit];

	int i, newvisit, dis;
	int min = INF;

	newvisit = visit - (1<<f);
	for(i=0;i<N;i++)
	{
		if(!w[i][f])	continue;
		if(newvisit & (1<<i))
		{
			dis = dp(i, newvisit) + w[i][f];
			if(min > dis)	min = dis;
		}
	}

	ca[f][visit] = min;
	return min;
}

int main(void)
{
	scanf("%d", &N);
	
	int i,j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
			scanf("%d", &w[i][j]);
	}

	printf("%d\n", dp(0,(1<<N)-1));
	return 0;
}
