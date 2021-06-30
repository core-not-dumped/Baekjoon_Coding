#include <stdio.h>

void main()
{
	printf("\x1b[31m");
	printf("RED\n");
	printf("RED??\n");
	printf("RED????\n");

	printf("\x1b[32m");
	printf("GREEN\n");

	printf("\x1b[0m");
	printf("NORMAL COLOR\n");

	printf("\x1b[33m"	"YELLOW\n");
}
