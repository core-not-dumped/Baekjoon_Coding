#include <stdio.h>

int main(void)
{
	int s;
	scanf("%d", &s);

	if(s < 60)	printf("F\n");
	else if(s < 70)	printf("D\n");
	else if(s < 80)	printf("C\n");
	else if(s < 90)	printf("B\n");
	else	printf("A\n");

	return 0;
}
