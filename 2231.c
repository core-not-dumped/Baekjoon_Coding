#include <stdio.h>

int create(int a)
{
	int sum = a;
	while(a>0)
	{
		sum += a%10;
		a /= 10;
	}
	return sum;
}

int main(void)
{
	int n[1000001];
	int N, i;
	scanf("%d", &N);

	for(i=0;i<N;i++)
	{
		if(create(i) == N)	break;
	}

	if(i==N)	printf("0\n");
	else	printf("%d\n", i);

	return 0;
}
