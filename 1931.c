#include <stdio.h>
#include <stdlib.h>

struct time{
	int s, e;
}t[100000];

int comp(const void *A, const void *B)
{
	struct time *pA = (struct time *)A;
	struct time *pB = (struct time *)B;

	if(pA->e < pB->e)	return -1;
	if(pA->e == pB->e)
	{
		if(pA->s < pB->s)	return -1;
		else	return 1;
	}
	return 1;
}

int main(void)
{
	int N;
	scanf("%d", &N);

	int i, j;
	for(i=0;i<N;i++)
		scanf("%d %d", &t[i].s, &t[i].e);

	qsort(t, N, sizeof(struct time), comp);

	int ans = 1;
	int ft = t[0].e;
	for(i=1;i<N;i++)
	{
		if(t[i].s >= ft)
		{
			ans++;
			ft = t[i].e;
		}
	}

	printf("%d\n", ans);

	return 0;
}
