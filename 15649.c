#include <stdio.h>

int N, M;
int num[10];
int ch[10];

void p(int w)
{
	int i;
	if(w==M)
	{
		for(i=0;i<M;i++)
			printf("%d ", num[i]);
		printf("\n");
		return;
	}
	
	for(i=1;i<N+1;i++)
	{
		if(!ch[i])
		{
			num[w] = i;
			ch[i] = 1;
			p(w+1);
			ch[i] = 0;
		}
	}
}

int main(void)
{
	scanf("%d %d", &N, &M);

	p(0);

	return 0;
}
