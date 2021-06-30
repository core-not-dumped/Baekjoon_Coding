#include <stdio.h>

int Graph[1001][1001]={0};
int DFSvisit[1001]={0};
int BFSvisit[1001]={0};
int queue[1001];

void DFS(int v, int N)
{
	int i;

	printf("\nDFSvisit:");
	for(i=0;i<N;i++)
	{
		printf("%d ", DFSvisit[i]);
	}
	printf("\n");

	DFSvisit[v] = 1;
	printf("%d ", v);

	for(i=1;i<=N;i++)
	{
		if(Graph[v][i]==1 && DFSvisit[i]==0)
			DFS(i,N);
	}

	return;
}

void BFS(int v, int N)
{
	int front = 0;
	int rear = 0;
	int Pop;
	int i;

	printf("%d ", v);
	queue[0] = v;
	rear++;
	BFSvisit[v] = 1;

	while(front<rear)
	{
		Pop = queue[front];
		front++;
	
		for(i=1;i<=N;i++)
		{
			if(Graph[Pop][i]==1 && BFSvisit[i]==0)
			{
				printf("%d ", i);
				queue[rear] = i;
				rear++;
				BFSvisit[i] = 1;
			}
		}
	}
}

int main(void)
{
	int N,M,Start;
	int i,x,y;

	scanf("%d %d %d", &N, &M, &Start);
	
	for(i=0;i<M;i++)
	{
		scanf("%d %d", &x, &y);
		Graph[x][y] = 1;
		Graph[y][x] = 1;
	}

	DFS(Start, N);
	printf("\n");
	BFS(Start, N);
	printf("\n");

	return 0;
}
