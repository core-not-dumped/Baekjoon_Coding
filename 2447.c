#include <stdio.h>

int main(void)
{
	int N;
	scanf("%d", &N);

	int i,j,k,num;
	int ch;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			num = 3;
			ch = 0;
			while(num <= N)
			{
				if(((i%num)/(num/3) == 1) && ((j%num)/(num/3) == 1))
				{
					ch = 1;
					break;
				}
				num *= 3;
			}
			if(ch == 1)	printf(" ");
			else
				printf("*");
		}
		printf("\n");
	}

	return 0;
}
