#include <stdio.h>

int main(void)
{
	double r,s1,s2;
	scanf("%lf", &r);

	s1 = r*r*3.14159265359;
	s2 = r*r*2;
	printf("%f\n", s1);
	printf("%f\n", s2);

	return 0;
}
