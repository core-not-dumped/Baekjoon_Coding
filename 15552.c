#include <stdio.h>

int main(void)
{
	int T;
	scanf("%d", &T);

	int i;
	for(i=0;i<T;i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", a+b);
	}

	return 0;
}
