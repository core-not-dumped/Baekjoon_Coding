#include <stdio.h>
#include <stdlib.h>

int N, p;
int **A;

int **m(int **arr)
{
	int i;
	arr = (int **) malloc(sizeof(int *) * N);
	for(i=0;i<N;i++)
		arr[i] = (int *) malloc(sizeof(int) * N);
	return arr;
}

int **po(long long B)
{
	if(B == 1)	return A;

	int i, j, k;
	int **tmp1 = m(tmp1);
	int **tmp2 = m(tmp2);
	int **tmp3 = m(tmp3);

	tmp1 = po(B/2);

	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			int sum = 0;
			for(k=0;k<N;k++)
				sum += tmp1[i][k] * tmp1[k][j];
			tmp2[i][j] = sum % p;
		}
	}

	if(B & 1)
	{
		for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
			{
				int sum = 0;
				for(k=0;k<N;k++)
					sum += tmp2[i][k] * A[k][j];
				tmp3[i][j] = sum % p;
			}
		}
		return tmp3;
	}
	else	return tmp2;
}

int main(void)
{
	long long B;
	scanf("%d %lld", &N, &B);
	p = 1000;

	A = m(A);
	int i, j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			scanf("%d", &A[i][j]);
			if(A[i][j] == 1000)	A[i][j] = 0;
		}
	}

	int **ans = m(ans);
	ans = po(B);

	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
			printf("%d ", ans[i][j]);
		printf("\n");
	}

	return 0;
}
