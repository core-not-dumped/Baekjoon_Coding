#include <stdio.h>
#include <memory.h>

int main(void)
{
	int M, N;
	scanf("%d %d", &M, &N);

	int ch[1000001];
	int j, i;
	memset(ch,0,sizeof(ch));
	ch[0] = 1;	ch[1] = 1;
	for(i=2;i<1000001;i++)
	{
		if(!ch[i])
		{
			for(j=2*i;j<1000001;j+=i)	ch[j] = 1;
		}
	}

	for(i=M;i<=N;i++)	{ if(!ch[i])	printf("%d\n", i); }

	return 0;
}
