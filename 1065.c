#include <stdio.h>

int han(int n)
{
	int o = n%10;
	n /= 10;
	int t = n%10;
	n /= 10;
	int h = n%10;

	if((o+h) == (2*t))	return 1;
	else	return 0;
}

int main(void)
{
	int N;
	scanf("%d", &N);

	if(N<=99)	{ printf("%d", N);	return 0; }
	if(N==1000)	{ printf("144\n");	return 0; }

	int i;
	int sum = 0;
	for(i=100;i<N+1;i++)
		sum += han(i);

	printf("%d\n", sum+99);

	return 0;
}
