#include <stdio.h>

int num;
int chV[16];
int chc1[30];
int chc2[30];
int N;
int rest;

void queen(int q)
{
	if(N==q)
	{
		num++;
		return;
	}

	int i;
	int start, range;
	if(q)
	{
		start = 0;
		range = N;
	}
	else if(!q && rest)
	{
		start = N/2;
		range = N/2+1;
	}
	else
	{
		start = 0;
		range = N/2;
	}

	for(i=start;i<range;i++)
	{
		if(!chV[i] && !chc1[i+q] && !chc2[i-q+N-1])
		{
			chV[i]=1;
			chc1[i+q] = 1;
			chc2[i-q+N-1] = 1;

			queen(q+1);

			chV[i]=0;
			chc1[i+q] = 0;
			chc2[i-q+N-1] = 0;
		}
	}
}

int main(void)
{
	scanf("%d", &N);
	
	num = 0;
	rest = 0;
	queen(0);
	num *= 2;

	if(!(N % 2))
		printf("%d\n", num);
	else
	{
		rest = 1;
		queen(0);
		printf("%d\n", num);
	}

	return 0;
}
