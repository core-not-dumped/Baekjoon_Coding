#include <stdio.h>
#include <memory.h>

int main(void)
{
	int M, N;
	scanf("%d %d", &M, &N);

	int ch[10001];
	int tmp, i;
	memset(ch,0,sizeof(ch));
	ch[0] = 1;	ch[1] = 1;
	for(i=2;i<10001;i++)
	{
		if(ch[i] == 0)
		{
			tmp = 2 * i;
			while(tmp < 10001)
			{ ch[tmp] = 1;	tmp += i; }
		}
	}

	int min;
	int sum = 0;
	for(i=M;i<=N;i++)	{ if(!ch[i])	{ min = i;	break; } }
	if(i == N+1)	{ printf("-1\n");	return 0; }
	for(i=M;i<=N;i++)	{ if(!ch[i])	sum += i; }

	printf("%d\n%d\n", sum, min);

	return 0;
}
