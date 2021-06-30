#include <stdio.h>

int main(void)
{
	int N;
	scanf("%d", &N);

	int i, j;
	int A[1000];
	for(i=0;i<N;i++)
		scanf("%d", &A[i]);

	int dp1[1000] = {1,};
	int dp2[1000] = {0,};
	for(i=1;i<N;i++)
	{
		dp1[i] = 1;
		for(j=0;j<i;j++)
		{
			if(A[j] < A[i] && dp1[i] < dp1[j] + 1)
			{
				dp1[i] = dp1[j] + 1;
				dp2[i] = j;
			}
		}
	}

	int ind;
	int max = 0;
	for(i=0;i<N;i++)
	{
		if(max < dp1[i])
		{
			ind = i;
			max = dp1[i];
		}
	}

	printf("%d\n", max);

	int maxtmp = max;
	int ans[1000];
	ans[max] = ind;
	while(max--)
	{
		ans[max] = dp2[ind];
		ind = dp2[ind];
	}

	for(i=1;i<=maxtmp;i++)
	printf("%d ", A[ans[i]]);
	printf("\n");

	return 0;
}
