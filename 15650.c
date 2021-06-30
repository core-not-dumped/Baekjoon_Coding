#include <stdio.h>

int N, M;
int num[10];

void p(int w, int s)
{
	int i;
	if(w==M)
	{
		for(i=0;i<M;i++)
			printf("%d ", num[i]);
		printf("\n");
		return;
	}
	
	for(i=s+1;i<N+1;i++)
	{
		num[w] = i;
		p(w+1, i);
	}
}

int main(void)
{
	scanf("%d %d", &N, &M);

	p(0, 0);

	return 0;
}
