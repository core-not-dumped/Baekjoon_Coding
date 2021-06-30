#include <stdio.h>
#include <stdlib.h>

struct line{
	int left;
	int right;
}l[100];

int comp(const void *A, const void  *B)
{
    struct line* ptrA = (struct line*)A;
    struct line* ptrB = (struct line*)B;

    if (ptrA->left < ptrB->left) return -1;
    else return 1;
}

int main(void)
{
	int N;
	scanf("%d", &N);

	int i, j;
	for(i=0;i<N;i++)
		scanf("%d %d", &l[i].left, &l[i].right);

	qsort(l, N, sizeof(struct line), comp);

	int dp[100] = {1,};
	int max;
	for(i=1;i<N;i++)
	{
		max = 1;
		for(j=0;j<i;j++)
		{
			if(l[i].right > l[j].right)
			{
				if(max < dp[j]+1)	max = dp[j]+1;
			}
		}
		dp[i] = max;
	}

	max = 0;
	for(i=0;i<N;i++)
	{
		if(max < dp[i])	max = dp[i];
	}

	printf("%d\n", N - max);
	return 0;
}
