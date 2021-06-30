#include <stdio.h>

int main(void)
{
	long double a, b;
	scanf("%Lf %Lf", &a, &b);
	
	printf("%.10Lf\n", a/b);

	return 0;
}
