#include <stdio.h>

int gcd(int a, int b)
{
	return b ? gcd(b, a%b) : a;
}

int main(void)
{
	int N;
	scanf("%d", &N);

	int r[100];
	int i;
	for(i=0;i<N;i++)
		scanf("%d", &r[i]);

	int g;
	for(i=1;i<N;i++)
	{
		g = gcd(r[0], r[i]);
		printf("%d/%d\n", r[0]/g, r[i]/g);
	}

	return 0;
}
