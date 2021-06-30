#include <stdio.h>

int num(int k, int a)
{
	int sum = 0;
	int mul = k;
	while(a/mul > 0)
	{
		sum += a/mul;
		a /= mul;
	}
	
	return sum;
}

int main(void)
{
	int m, n;
	scanf("%d %d", &n, &m);
	
	int ans5 = num(5, n) - num(5, n-m) - num(5, m);
	int ans2 = num(2, n) - num(2, n-m) - num(2, m);
	
	printf("%d\n", ans5 > ans2 ? ans2 : ans5);
	
	return 0;
}
