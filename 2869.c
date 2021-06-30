#include <stdio.h>

int main(void)
{
	int a, b, v;
	scanf("%d %d %d", &a, &b, &v);

	if(a > v)	{ printf("1\n");	return 0; }

	v -= a;
	if(v%(a-b) == 0)
		printf("%d\n", v/(a-b)+1);
	else
		printf("%d\n", v/(a-b)+2);

	return 0;
}
