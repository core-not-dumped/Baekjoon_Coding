#include <stdio.h>
#include <stdlib.h>

long long calc(long long a,long long b,long long c)
{
	if(b == 0) return 1;
	
	long long v;	
	v = calc(a,b/2,c);
	v = v * v % c;
	
	if(b%2)		return (v * a) % c;	
	else		return v;
}

int main(void) {
	long long a,b,c,ret;
	scanf("%lld %lld %lld",&a,&b,&c);
	
	printf("%lld\n",calc(a,b,c));
	return 0;
}
