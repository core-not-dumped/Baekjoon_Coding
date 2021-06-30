#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <memory.h>

typedef struct Line{
	int u, v, w;
}L;
L l[300000];

typedef struct e{
	int v, w;
}Edge;
Edge *edge[20001];

struct h{
	int d, i;
}heap[300000];

int heap_size;

void insert_min_heap(int dnum, int inum)
{
	int cur = ++heap_size;
	while(cur != 1)
	{
		if(heap[cur/2].d > dnum)
			heap[cur] = (struct h) {heap[cur/2].d, heap[cur/2].i};
		else	break;
		cur /= 2;
	}
	heap[cur] = (struct h) {dnum, inum};
}

void delete_min_heap(int *itemd, int *itemi)
{
	*itemd = heap[1].d;
	*itemi = heap[1].i;
	int dtmp = heap[heap_size].d;
	int itmp = heap[heap_size--].i;
	int cur = 2;
	while(cur <= heap_size)
	{
		int minind = heap[cur].d < heap[cur+1].d ? cur : cur+1;

		if(heap[minind].d < dtmp)
			heap[cur/2] = (struct h) {heap[minind].d, heap[minind].i};
		else	break;

		cur = minind * 2;
	}
	heap[cur/2] = (struct h) {dtmp, itmp};
}

int main(void)
{
	heap_size = 0;

	int V, E, K;
	scanf("%d %d %d", &V, &E, &K);

	int i, j;
	int cnt[20001] = {0};
	for(i=0;i<E;i++)
	{
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		l[i] = (L) {u, v, w};
		cnt[u]++;
	}

	int dist[20001];
	for(i=0;i<=V;i++)
	{
		dist[i] = INT_MAX;
		edge[i] = (Edge *)malloc(sizeof(Edge) * cnt[i]);
		cnt[i] = 0;
	}
	dist[K] = 0;

	for(i=0;i<E;i++)
	{
		int s = l[i].u;
		edge[s][cnt[s]] = (Edge) { l[i].v, l[i].w };
		cnt[s]++;
	}

	insert_min_heap(dist[K], K);

	while(heap_size)
	{
		int newd, newi;
		delete_min_heap(&newd, &newi);

		if(newd > dist[newi])	continue;

		for(i=0;i<cnt[newi];i++)
		{
			int see = edge[newi][i].v;
			int sdist = dist[newi] + edge[newi][i].w;
			if(sdist < dist[see])
			{
				dist[see] = sdist;
				insert_min_heap(sdist, see);
			}
		}
	}

	for(i=1;i<=V;i++)
	{
		if(dist[i] == INT_MAX)	printf("INF\n");
		else	printf("%d\n", dist[i]);
	}

	return 0;
}
