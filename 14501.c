#include <stdio.h>

int max;
int N;
int T[15], P[15];
int ch[15];

void DFS(int d)
{
	int i;
	if(d == N)
	{
		int money = 0;
		for(i=0;i<N;i++)
		{
			if(ch[i] == 1)
				money += P[i];
		}
			
		if(max < money)
			max = money;
		return;
	}

	if(d+T[d] <= N && ch[d] == 0)
	{
		ch[d] = 1;
		for(i=1;i<T[d];i++)
			ch[d+i] = 2;
	}
	DFS(d+1);
	if(ch[d] == 1)
	{
		for(i=0;i<T[d];i++)	ch[d+i] = 0;
	}
	DFS(d+1);
}

int main(void)
{
	scanf("%d", &N);

	int i;
	for(i=0;i<N;i++)
		scanf("%d %d", &T[i], &P[i]);

	for(i=0;i<N;i++)	ch[i] = 0;
	max = 0;
	DFS(0);

	printf("%d\n", max);

	return 0;
}
