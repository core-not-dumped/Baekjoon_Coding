#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int main(void)
{
	int N;
	int i,j,k,l;
	scanf("%d", &N);

	int h[101][101];
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
			scanf("%d",&h[i][j]);
	}

	int htmp[101][101];
	int H[4] = {1,-1,0,0};
	int V[4] = {0,0,1,-1};
	int qH[10001];
	int qV[10001];
	int r, f;
	int a,b;

	int max = 1;
	int num;

	for(i=1;i<100;i++)
	{
		num = 0;

		for(j=0;j<N;j++)
			memset(htmp[j],0,sizeof(htmp[j]));
	
		for(j=0;j<N;j++)
		{
			for(k=0;k<N;k++)
			{
				if(h[j][k] > i)
					htmp[j][k] = 1;
			}
		}

		for(j=0;j<N;j++)
		{
			for(k=0;k<N;k++)
			{
				if(htmp[j][k] == 1)
				{
					f = 0;
					r = 0;
					qH[0] = j;
					qV[0] = k;
					htmp[j][k] = 2;
					num++;

					while(r<=f)
					{
						for(l=0;l<4;l++)
						{
							a = qH[r]+H[l];
							b = qV[r]+V[l];
							if(a<0 || a>=N || b<0 || b>=N)	continue;
							if(htmp[a][b] == 1)
							{
								htmp[a][b] = 2;
								f++;
								qH[f] = a;
								qV[f] = b;
							}
						}
						r++;
					}
				}
			}
		}

		if(num > max)	max = num;
	}

	printf("%d\n", max);

	return 0;
}
