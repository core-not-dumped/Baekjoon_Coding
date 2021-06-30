#include <stdio.h>

int func(int n)
{
	if (n < 2)	return 0;

	int a, b;
	a = (func(n / 2) + 1) + n % 2;
	b = (func(n / 3) + 1) + n % 3;

	return (a < b) ? a : b;
}

int main(void)
{
	int n;
	scanf("%d", &n);
	printf("%d\n", func(n));
	return 0;
}
