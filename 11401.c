#include <stdio.h>

long long p = 1000000007;
long long x;

void eu(long long r0, long long r1, long long s0, long long s1, long long t0, long long t1)
{
	if(!r1)		{ x = t0;	return; }
	long long q = r0 / r1;
	eu(r1, r0-r1*q, s1, s0-s1*q, t1, t0-t1*q);
}

int main(void)
{
	int N, K;
	scanf("%d %d", &N, &K);

	int i;
	long long fact[4000000] = {1,};
	for(i=1;i<=N;i++)
		fact[i] = (fact[i-1] * i) % p;

	long long A = fact[N];
	long long B = (fact[N-K] * fact[K]) % p;

	eu(p,B,1,0,0,1);

	//printf("A B x: %lld %lld %lld\n", A, B, x);

	if(x < 0)	x += p;
	printf("%lld\n", (A*x)%p);

	return 0;
}
