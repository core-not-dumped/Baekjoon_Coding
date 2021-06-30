#include <stdio.h>

int S[21][21];
int min, N;
int ch[21];

void mincheck()
{
	int start = 0, link = 0;
	int one[11], zero[11];
	int k1 = 0, k2 = 0;
	int i, j, diff;

	for(i=0;i<N;i++)
	{
		if(ch[i])	one[k1++] = i;
		else	zero[k2++] = i;
	}

	for(i=0;i<N/2;i++)
	{
		for(j=0;j<N/2;j++)
		{
			start += S[one[i]][one[j]];
			link += S[zero[i]][zero[j]];
		}
	}

	if(start > link)	diff = start - link;
	else	diff = link - start;

	if(min > diff)	min = diff;
	return;
}

void check(int look, int num)
{
	if(look == N && num == N/2)
	{
		mincheck();
		return;
	}

	if(look >= N)	return;
	if(num > N/2)	return;

	ch[look] = 0;
	check(look+1, num);

	ch[look] = 1;
	check(look+1, num+1);
}

int main(void)
{
	scanf("%d", &N);

	int i,j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
			scanf("%d", &S[i][j]);
	}

	min = 1000000;
	check(0,0);

	printf("%d\n", min);
	return 0;
}
