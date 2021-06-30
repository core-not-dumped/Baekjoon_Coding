#include <stdio.h>

int main(void)
{
	int N;
	scanf("%d", &N);
	
	int w[51], h[51], map[51];
	int i,j;
	for(i=0;i<N;i++)
		scanf("%d %d", &w[i], &h[i]);

	int r;
	for(i=0;i<N;i++)
	{
		r = 1;
		for(j=0;j<N;j++)
		{
			if(h[i]<h[j] && w[i]<w[j])	r++;
		}
		map[i] = r;
	}

	for(i=0;i<N;i++)
		printf("%d ", map[i]);
	printf("\n");

	return 0;
}
