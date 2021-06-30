#include <stdio.h>

int main(void)
{
	int N;
	scanf("%d", &N);

	int i;
	int p[1000001];
	for(i=0;i<N;i++)
		scanf("%d", &p[i]);
	
	int B, C;
	scanf("%d %d", &B, &C);
	
	long long ans = 0;
	for(i=0;i<N;i++)
	{
		if(p[i] <= B)	ans++;
		else
		{
			p[i] -= B;
			ans ++;
		
			ans += (p[i] - 1) / C + 1;
		}
	}

	printf("%lld\n", ans);

	return 0;
}
