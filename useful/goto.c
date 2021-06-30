#include <stdio.h>

int main(void)
{
	int n = 0;

	/*ONE:
		printf("1\n");
		n++;
		if(n == 1)	return 0;
	goto ONE;*/


	int i, j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("2\n");
			goto EXIT;
		}
		EXIT: continue;
	}

	return 0;
}
