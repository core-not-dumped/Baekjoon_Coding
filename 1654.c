#include <stdio.h>
#include <limits.h>

long long l[10000];
long long K, N;

long long piece(long long p)
{
	if(p == 0)	return LLONG_MAX;
	
	int i;
	long long ans = 0;
	for(i=0;i<K;i++)
		ans += l[i] / p;
	return ans;
}

long long Bsearch(long long s, long long e)
{
	if(s+1 == e)
	{
		if(piece(e) >= N)	return e;
		else	return s;
	}
	if(s == e)	return s;
	long long h = (s+e)/2;
	
	if(piece(h) >= N)	Bsearch(h,e);
	else	Bsearch(s,h);
}

int main(void)
{
	scanf("%lld %lld", &K, &N);
	
	int i;
	for(i=0;i<K;i++)
		scanf("%lld", &l[i]);
		
	printf("%lld\n", Bsearch((long long)1, (long long)INT_MAX));
	
	return 0;
}
