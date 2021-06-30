#include <stdio.h>
#include <stdlib.h>

int hor[11], ver[11], squ[11];
int qH[101], qV[101];
int map[11][11];
int ind;

void back(int N)
{
	int i, j;

	if(N == ind)
	{
		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
				printf("%d ", map[i][j]);
			printf("\n");
		}
		printf("\n");

		exit(0);
	}

	int H = qH[N];
	int V = qV[N];
	int S = H/3*3+V/3;

	int com = 1;
	for(i=1;i<10;i++)
	{
		com = com << 1;
		if(!((hor[H] | ver[V] | squ[S]) & com))
		{
			hor[H] |= com;
			ver[V] |= com;
			squ[S] |= com;
			map[H][V] = i;

			back(N+1);

			hor[H] &= (~com);
			ver[V] &= (~com);
			squ[S] &= (~com);
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
			{
				if(map[i][j] == 0)
				{
					qH[ind] = i;
					qV[ind] = j;
					ind++;
				}
				else
				{
					hor[i] |= (1 << map[i][j]);
					ver[j] |= (1 << map[i][j]);
					squ[i/3*3+j/3] |= (1 << map[i][j]);
				}
			}
		}
	}

	back(0);
}
