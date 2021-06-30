#include <stdio.h>

int N, M;
int map[101];
int mapch[101];
int max;

void check()
{
	int i;
	int sum = 0;
	for(i=0;i<N;i++)
	{
		if(mapch[i])	sum += map[i];
	}
	if(max < sum && sum <= M)	max = sum;
}

void DFS(int ch, int num)
{
	if(num == 3 && ch == N)
		check();

	if(ch >= N)	return;
	if(num >= 4)	return;
	
	mapch[ch] = 1;
	DFS(ch+1,num+1);
	mapch[ch] = 0;
	DFS(ch+1,num);
}

int main(void)
{
	scanf("%d %d", &N, &M);

	int i;
	for(i=0;i<N;i++)
		scanf("%d", &map[i]);

	max = 0;
	DFS(0,0);

	printf("%d\n", max);
	
	return 0;
}
