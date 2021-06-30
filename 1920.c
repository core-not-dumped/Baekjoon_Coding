#include <stdio.h>
#include <stdlib.h>

int N, M;
int a[100000];

int comp(const void *A, const void *B)
{
	if(*(int *)A < *(int *)B)	return -1;
	if(*(int *)A > *(int *)B)	return 1;
	else	return 0;
}

int Bsearch(int num, int s, int e)
{
	if(s+1 == e)
	{
		if(a[s] == num)	return 1;
		if(a[s+1] == num)	return 1;
		else	return 0;
	}
	if(s == e)
	{
		if(a[s] == num)	return 1;
		else	return 0;
	}

	int h = (s+e)/2;
	if(a[h] == num)	return 1;
	if(a[h] < num)	return Bsearch(num,h+1,e);
	if(a[h] > num)	return Bsearch(num,s,h-1);
}

int main(void)
{
	scanf("%d", &N);
	
	int i;
	for(i=0;i<N;i++)
		scanf("%d", &a[i]);

	qsort(a,N,sizeof(int),comp);

	scanf("%d", &M);

	for(i=0;i<M;i++)
	{
		int num;
		scanf("%d", &num);
		
		printf("%d\n", Bsearch(num, 0, N-1));
	}

	return 0;
}
