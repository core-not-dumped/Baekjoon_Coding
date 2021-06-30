#include <stdio.h>

int main(void)
{
	int N, K;
	scanf("%d %d", &N, &K);

	int m[10], i;
	for(i=0;i<N;i++)
		scanf("%d", &m[i]);

	int cnt = 0;
	for(i=N-1;i>=0;i--)
	{
		cnt += K/m[i];
		K %= m[i];
	}

	printf("%d\n", cnt);

	return 0;
}
