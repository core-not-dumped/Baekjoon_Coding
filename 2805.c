#include <stdio.h>

long long N, M;
long long t[1000000];

long long tree(int height)
{
	long long ans = 0;
	int i;
	for(i=0;i<N;i++)
	{
		if(t[i] - height > 0)
		ans += t[i] - height;
	}
	return ans;
}

long long Bsearch(long long s, long long e)
{
	if(s+1 == e)
	{
		if(tree(e) >= M)	return e;
		else	return s;
	}
	if(s == e)	return s;
	
	long long h = (s + e)/2;
	if(tree(h) >= M)	Bsearch(h,e);
	else				Bsearch(s,h);
}

int main(void)
{
	scanf("%lld %lld", &N, &M);
	
	int i;
	for(i=0;i<N;i++)
	scanf("%lld", &t[i]);
	
	printf("%lld", Bsearch(0,1000000000));
	
	return 0;
}
