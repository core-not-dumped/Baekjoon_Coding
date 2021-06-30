#include <stdio.h>

int main(void)
{
	int a,b;
	scanf("%d %d", &a, &b);

	a > b ? printf(">\n") : (a == b ? printf("==\n") : printf("<\n"));

	return 0;
}
