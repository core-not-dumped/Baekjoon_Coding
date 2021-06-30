#include <stdio.h>

int ch666(int n)
{
	int cnt = 0;
	while(n>0)
	{
		if(n%10 == 6)
		{
			cnt++;
			if(cnt == 3)	return 1;
		}
		else	cnt = 0;

		n /= 10;
	}
	return 0;
}

int main(void)
{
	int N;
	scanf("%d", &N);
	
	int num = 665;
	int cnt = 0;
	while(cnt < N)
	{
		num++;
		if(ch666(num))	cnt++;
	}

	printf("%d\n", num);

	return 0;
}
