#include <stdio.h>
#include <memory.h>

int big(int a, int b)
{
	return a>b?a:b;
}

int main(void)
{
	int N;
	scanf("%d", &N);
	
	int A[1001], B[1001];
	int i, j, dp1[1001], dp2[1001];
	memset(dp1,0,sizeof(dp1));
	memset(dp2,0,sizeof(dp2));

	for(i=0;i<N;i++)
	{
		scanf("%d", &A[i]);
		B[N-i-1] = A[i];
	}

	dp1[0] = dp2[0] = 1;
	for(i=1;i<N;i++)
	{
		for(j=0;j<i;j++)
		{
			if(A[i] > A[j] && dp1[i] < dp1[j])	dp1[i] = dp1[j];
			if(B[i] > B[j] && dp2[i] < dp2[j])	dp2[i] = dp2[j];
		}
		dp1[i]++;
		dp2[i]++;
	}

	int max = 0;
	for(i=0;i<N;i++)
		max = big(dp1[i] + dp2[N-i-1] - 1, max);

	printf("%d\n", max);

	return 0;
}
