#include <stdio.h>

int main(void)
{
	int N;
	scanf("%d", &N);

	long long k[100000];
	long long l[100000];
	int i, j;
	for(i=0;i<N-1;i++)
	scanf("%lld", &k[i]);

	for(i=0;i<N;i++)
	scanf("%lld", &l[i]);

	long long sum = 0;
	for(i=0;i<N;i++)
	{
		for(j=i+1;j<N;j++)
		{
			sum += l[i] * k[j-1];
			if(l[i] > l[j])	break;
		}
		i = j-1;
	}

	printf("%lld\n", sum);

	return 0;
}
