#include <stdio.h>

int main(void)
{
	int a,b;
	scanf("%d %d", &a, &b);

	int o1 = a%10;
	int o2 = b%10;
	a /= 10;
	b /= 10;

	int t1 = a%10;
	int t2 = b%10;
	a/= 10;
	b/= 10;

	int h1 = a%10;
	int h2 = b%10;

	int a1 = o1*100+t1*10+h1;
	int b1 = o2*100+t2*10+h2;

	if(a1 > b1)	printf("%d\n", a1);
	else	printf("%d\n", b1);
	
	return 0;
}
