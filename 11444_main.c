#include <stdio.h>

long long m[1000];
long long mn[1000];
int ch;
long long p;

long long fib(long long n)
{
	if(n == 0)	return 0;
	if(n == 1)	return 1;

	long long f1, f2;
	int i;
	for(i=0;i<ch;i++)
	{
		if(mn[i] == n/2 - 1)
		{
			f1 = m[i];
			break;
		}
	}
	if(i == ch)
	{
		f1 = fib(n/2 - 1);
		m[ch] = f1;
		mn[ch] = n/2 - 1;
		ch++;
	}

	for(i=0;i<ch;i++)
	{
		if(mn[i] == n/2)
		{
			f2 = m[i];
			break;
		}
	}
	if(i == ch)
	{
		f2 = fib(n/2);
		m[ch] = f2;
		mn[ch] = n/2;
		ch++;
	}

	if(n & 1)	return ((f2 * f2) % p + (f1 + f2) * (f1 + f2) % p) % p;
	else		return ((f2 * f2) % p + (2 * f1 * f2) % p) % p;
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
