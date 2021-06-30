#include <stdio.h>

int main(void)
{
	int A[100][100], B[100][100];
	int N, M, K, i, j, k;
	scanf("%d %d", &N, &M);
	
	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
			scanf("%d", &A[i][j]);
	}

	scanf("%d %d", &M, &K);
	for(i=0;i<M;i++)
	{
		for(j=0;j<K;j++)
			scanf("%d", &B[i][j]);
	}

	for(i=0;i<N;i++)
	{
		for(j=0;j<K;j++)
		{
			int sum = 0;
			for(k=0;k<M;k++)
				sum += A[i][k] * B[k][j];
			printf("%d ", sum);
		}
		printf("\n");
	}

	return 0;
}
