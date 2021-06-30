#include <stdio.h>

long long r[100];

void res(long long B, long long C)
{
	r[B] = r[B - 1] * r[B - 1] % C;
	if(B == 31)	return;
	res(B+1, C);
}

int main(void)
{
	long long A, B, C;
	scanf("%lld %lld %lld", &A, &B, &C);
	
	r[0] = A % C;
	res((long long)1,C);
	
	int i;
	long long ans = 1;
	for(i=0;i<=31;i++)
	{
		if(B % 2)	ans *= r[i];
		ans %= C;
		B >>= 1;
	}
	printf("%d\n", ans);
	
	return 0;
}
