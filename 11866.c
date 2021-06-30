#include <stdio.h>

int main(void)
{
	int N, K;
	scanf("%d %d", &N, &K);

	int i;
	int q[1000000];
	for(i=1;i<=N;i++)
		q[i-1] = i;

	printf("<");
	int ch = 0;
	int r = 0, f = N;
	while(ch < N-1)
	{
		for(i=0;i<K-1;i++)
			q[f++] = q[r++];

		printf("%d, ", q[r]);
		ch++;
		r++;
	}

	printf("%d", q[f-1]);
	printf(">\n");

	return 0;
}
