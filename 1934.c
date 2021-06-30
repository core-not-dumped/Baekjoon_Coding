#include <stdio.h>

int gcd(int a, int b)
{
	return b?gcd(b, a%b):a;
}

int main(void)
{
	int T;
	scanf("%d\n", &T);

	int i;
	for(i=0;i<T;i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		if(a > b)
			printf("%d\n", a*b/gcd(a,b));
		else
			printf("%d\n", a*b/gcd(b,a));
	}

	return 0;
}
