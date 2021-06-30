#include <stdio.h>

int min;
int m[51][51];

void ch(int h, int v)
{
	int i, j;
	int w = 0, b = 0;
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			if((i+j)%2 == 0)
			{
				if(m[h+i][v+j])	w++;
				else	b++;
			}
			else
			{
				if(!m[h+i][v+j])	w++;
				else	b++;
			}
		}
	}
	if(min > b)	min = b;
	if(min > w)	min = w;
}

int main(void)
{
	int N, M;
	scanf("%d %d", &N, &M);

	int i, j;
	char map[51][51];
	char WB;
	for(i=0;i<N;i++)
	{
		scanf("%s", map[i]);
		for(j=0;j<M;j++)
		{
			if(map[i][j] == 'B')	m[i][j] = 0;
			if(map[i][j] == 'W')	m[i][j] = 1;
		}
	}

	min = 3000;
	for(i=0;i<N-7;i++)
	{
		for(j=0;j<M-7;j++)
			ch(i,j);
	}

	printf("%d\n", min);

	return 0;
}
