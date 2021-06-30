#include <stdio.h>

int main(void)
{
	int N;
	scanf("%d", &N);
	
	char str[51];
	scanf("%s", str);
	
	int i;
	long long ans = 0;
	long long mul = 1;
	long long p = 1234567891;
	for(i=0;i<N;i++)
	{
		ans += (str[i] - 'a' + 1) * mul % p;
		ans %= p;
		mul *= 31;
		mul %= p;
	}
	
	printf("%lld\n", ans);
	
	return 0;
}
