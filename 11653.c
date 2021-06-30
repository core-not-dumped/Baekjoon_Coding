#include <stdio.h>

int main(void)
{
	int N;
	scanf("%d", &N);

	int i;
	for(i=2;i<10000001;i++)
	{
		if(N < i)	break;
		while(1)
		{
			if(!(N % i))
			{
				printf("%d\n", i);
				N /= i;
			}
			else	break;
		}
	}

	return 0;
}
