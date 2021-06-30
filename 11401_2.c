#include <stdio.h>

long long p = 1000000007;

long long poww(long long B, long long po, long long p)
{
	if(po == 1)	return 1;
	if(po == 1)	return B%p;

	long long v = poww(B, po >> 1 , p);
	v = v * v % p;
	if(po & 1)	return v * B % p;
	else		return v;
}

int main(void)
{
	int N, K;
	scanf("%d %d", &N, &K);

	int i;
	long long A = 1, B = 1;
	K = K < N-K ? K : N-K;
	for(i=1;i<=K;i++)
	{
		A = (A * (N-i+1)) % p;
		B = (B * i) % p;
	}

	printf("%lld\n", (A * poww(B, p-2, p))%p);

	return 0;
}
