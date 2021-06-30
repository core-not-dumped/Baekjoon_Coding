#include <stdio.h>
#include <memory.h>

int big(int a, int b, int c)
{
	int n;
	n = (a>b)?a:b;
	return (n>c)?n:c;
}

int main(void)
{
	int N;
	scanf("%d", &N);

	int i;
	int g[10001];
	for(i=0;i<N;i++)
		scanf("%d", &g[i]);

	int d[10001];
	memset(d,0,sizeof(d));

	d[0] = g[0];
	d[1] = g[0]+g[1];

	for(i=2;i<N;i++)
		d[i] = big(d[i-3] + g[i-1] + g[i], d[i-2] + g[i], d[i-1]);

	printf("%d\n", d[N-1]);

	return 0;
}
