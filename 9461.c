#include <stdio.h>

int main(void)
{
	int i;
	long long pa[101];
	pa[1] = pa[2] = pa[3] = 1;
	pa[4] = pa[5] = 2;
	for(i=1;i<96;i++)
		pa[i+5] = pa[i+4] + pa[i];
	
	int T,t;
	scanf("%d", &T);
	for(t=0;t<T;t++)
	{
		int N;
		scanf("%d", &N);
		printf("%lld\n", pa[N]);
	}

	return 0;
}
