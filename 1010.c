#include <stdio.h>

int main(void)
{
	int t;
	scanf("%d", &t);
	
	int i,j;
	int pa[31][31];
	
	for(i=0;i<=30;i++)
	{
		for(j=0;j<=30;j++)
			pa[i][j] = 0;
	}
	
	for(i=0;i<31;i++)
		pa[i][0] = 1;

	for(i=1;i<=30;i++)
	{
		for(j=1;j<=i;j++)
			pa[i][j] = pa[i-1][j-1] + pa[i-1][j];
	}
	
	while(t--)
	{
		int n, m;
		scanf("%d %d", &n, &m);
		
		printf("%d\n", pa[m][n]);
	}
	
	return 0;
}
