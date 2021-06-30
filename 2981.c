#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b)
{
	if(*(int *)a > *(int *)b)
		return 1;
	else if(*(int *)a < *(int *)b)
		return -1;
	else
		return 0;
}

int gcd(int a, int b)
{
	return b ? gcd(b, a%b) : a;
}

int main(void)
{
	int N;
	scanf("%d", &N);
	
	int i;
	int num[100];
	for(i=0;i<N;i++)
		scanf("%d", &num[i]);

	qsort(num,N,sizeof(int),comp);

	int de[100];
	for(i=0;i<N-1;i++)
		de[i] = num[i+1] - num[i];

	int max = de[0];
	for(i=1;i<N-1;i++)
		max = gcd(de[i], max);

	int me[100000];
	int p = 0;
	for(i=1;i*i<=max;i++)
	{
		if(max % i == 0)
		{
			if(i*i == max)	me[p++] = i;
			else
			{
				me[p++] = i;
				me[p++] = max/i;
			}
		}
	}

	qsort(me,p,sizeof(int),comp);

	for(i=1;i<p;i++)
		printf("%d ", me[i]);
	printf("\n");

	return 0;
}
