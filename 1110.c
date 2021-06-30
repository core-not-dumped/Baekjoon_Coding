#include <stdio.h>

int main(void)
{
	int N;
	scanf("%d", &N);
	
	int init = N;
	int cnt = 0;
	int a,b;
	while(1)
	{
		a = N%10;
		b = N/10;
		N = (a + b)%10 + a*10;
		cnt++;
		if(init == N)
		{
			printf("%d\n", cnt);
			return 0;
		}
	}

	return 0;
}
