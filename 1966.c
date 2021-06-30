#include <stdio.h>

int main(void)
{
	int t;
	scanf("%d", &t);

	while(t--)
	{
		int N, M;
		scanf("%d %d", &N, &M);

		int i;
		int im[100];
		int q[10000];
		for(i=0;i<N;i++)
			scanf("%d", &im[i]);

		for(i=1;i<=N;i++)
			q[i-1] = i;

		int r = 0, f = N;
		int pr = 0;
		while(r < f)
		{
			for(i=r+1;i<f;i++)
			{
				if(im[q[r]-1] < im[q[i]-1])
				{
					q[f++] = q[r++];
					break;
				}
			}
			if(i == f)
			{
				if(q[r] == M + 1)
				{
					printf("%d\n", pr + 1);
					break;
				}
				else	{	r++;	pr++;	}
			}
		}
	}

	return 0;
}
