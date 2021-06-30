#include <stdio.h>

int N, C;
int x[200000];

int comp(const void *A, const void *B)
{
	if(*(int *)A < *(int *)B)	return -1;
	if(*(int *)A > *(int *)B)	return 1;
	else	return 0;
}

int ch(int in)
{
	int num = C - 1;
	int i;
	int cur = x[0];
	for(i=1;i<N;i++)
	{
		if(cur + in <= x[i])
		{
			cur = x[i];
			num--;
			if(num == 0)	return 1;
		}
	}
	return 0;
}

int Bsearch(int s, int e)
{
	if(s+1 == e)
	{
		if(ch(e))	return e;
		else		return s;
	}
	if(s == e)	return s;
	
	int h = (s + e) / 2;
	if(ch(h))	Bsearch(h,e);
	else		Bsearch(s,h);
}

int main(void)
{
	scanf("%d %d", &N, &C);
	
	int i;
	for(i=0;i<N;i++)
		scanf("%d", &x[i]);
	
	qsort(x,N,sizeof(int),comp);
	
	int l = x[N-1] - x[0];
	int dis = l / (C - 1) + 1;
	
	printf("%d", Bsearch(1,dis));
	
	return 0;
}
