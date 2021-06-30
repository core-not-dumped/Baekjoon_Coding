#include <stdio.h>

int main(void)
{
	int N, K;
	scanf("%d %d", &N, &K);
	
	int pa[1001][1001];
	int i, j;
	for(i=0;i<1001;i++)
		pa[i][0] = 1;

	for(i=1;i<=N;i++)
	{
		for(j=1;j<=i;j++)
		{
			pa[i][j] = pa[i-1][j-1] + pa[i-1][j];
			if(pa[i][j] >= 10007)
				pa[i][j] %= 10007;
		}
	}

	printf("%d\n", pa[N][K]);
	
	return 0;
}
