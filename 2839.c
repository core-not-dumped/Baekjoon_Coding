#include <stdio.h>

int main(void)
{
	int N;
	scanf("%d", &N);
	
	if(N==4 || N==7)
	{
		printf("-1\n");
		return 0;
	}

	if(N%5 == 0)
		printf("%d\n", N/5);
	else if(N%5 == 1)
		printf("%d\n", (N-6)/5+2);
	else if(N%5 == 2)
		printf("%d\n", (N-12)/5+4);
	else if(N%5 == 3)
		printf("%d\n", (N-3)/5+1);
	else
		printf("%d\n", (N-9)/5+3);

	return 0;
}
