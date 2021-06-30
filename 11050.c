#include <stdio.h>

int main(void)
{
	int N, K;
	scanf("%d %d", &N, &K);
	
	int ans = 1;
	int i;
	for(i=N;i>N-K;i--)
		ans *= i;
	for(i=1;i<=K;i++)
		ans /= i;
		
	printf("%d\n", ans);
}
