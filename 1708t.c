#include <stdio.h>

int main(void)
{
	printf("90000\n");
	
	int i, j;
	for(i=0;i<300;i++)
	{
		for(j=0;j<300;j++)
		printf("%d %d\n", 200 * i, 200 * j);
	}
}
