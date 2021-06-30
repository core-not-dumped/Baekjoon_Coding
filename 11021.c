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
		printf("Case #%d: %d\n", i+1,a+b);
	}

	return 0;
}
