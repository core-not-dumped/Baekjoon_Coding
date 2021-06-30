#include <stdio.h>

int main(void)
{
	int i;
	int a, max = 0, index;
	for(i=0;i<9;i++)
	{
		scanf("%d", &a);
		if(max < a)
		{
			max = a;
			index = i+1;
		}
	}

	printf("%d\n%d\n", max, index);
	
	return 0;
}
