#include <stdio.h>

long long m[100000];
long long mn[100000];
int ch;
long long p;

long long fib(long long n)
{
	if(n == 0)	return 0;
	if(n == 1)	return 1;

	long long f[2];
	int fp[2] = {-1, 0};
	int i, j;
	for(i=0;i<2;i++)
	{
		for(j=0;j<ch;j++)
		{
			if(mn[j] == n/2 + fp[i])
			{
				f[i] = m[j];
				break;
			}
		}
		if(j == ch)
		{
			f[i] = fib(n/2 + fp[i]);
			m[ch] = f[i];
			mn[ch] = n/2 + fp[i];
			ch++;
		}
	}

	if(n & 1)	return ((f[1] * f[1]) % p + (f[0] + f[1]) * (f[0] + f[1]) % p) % p;
	else		return ((f[1] * f[1]) % p + (2 * f[0] * f[1]) % p) % p;
}

int main(void)
{
	long long n;
	scanf("%lld", &n);

	p = 1000000007;

	ch = 0;
	printf("%lld\n", fib(n));

	return 0;
}
