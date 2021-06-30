#include <stdio.h>

int main(void)
{
	int a, b;
	scanf("%d %d", &a, &b);

	int tmp;
	if(a < b)
	{
		tmp = a;
		a = b;
		b = tmp;
	}

	int i, max;
	for(i=1;i<=b;i++)
	{
		if(a % i == 0 && b % i == 0)
			max = i;
	}

	int min = a * b / max;

	printf("%d\n%d\n", max, min);

	return 0;
}
