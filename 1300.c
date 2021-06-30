#include <stdio.h>

int main(void)
{
	int N, k;
	scanf("%d %d", &N, &k);

	int left = 1;
	int right = k;
	int ans;
	while(left <= right)
	{
		int mid = (left + right) / 2;

		int i;
		long long cnt = 0;
		for(i=1;i<=N;i++)
			cnt += mid/i > N ? N : mid/i;

		if(cnt < k)	left = mid +1;
		else
		{
			ans = mid;
			right = mid - 1;
		}
	}
	printf("%d\n", ans);

	return 0;
}
