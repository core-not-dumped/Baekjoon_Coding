#include <stdio.h>

int main(void)
{
	int a, b;
	scanf("%d %d", &a, &b);

	int last;
	last = a*b;

	printf("%d\n",a*(b%10));
	b /= 10;
	printf("%d\n",a*(b%10));
	b /= 10;
	printf("%d\n",a*(b%10));

	printf("%d\n", last);

	return 0;
}
