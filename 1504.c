#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define MAX 9000000

int V, E, K;
int dist[20001];
int cnt[20001];
int heap_size;

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

int dijest(int start, int end)
{
	int i;
	for(i=1;i<=V;i++)
		dist[i] = MAX;
	dist[start] = 0;

	heap_size = 0;
	insert_min_heap(dist[start], start);
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
	return dist[end];
}

int main(void)
{
	scanf("%d %d", &V, &E);

	int i, j;
	memset(cnt,0,sizeof(cnt));
	for(i=0;i<E;i++)
	{
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		l[2*i] = (L) {u, v, w};
		l[2*i+1] = (L) {v, u, w};
		cnt[u]++;
		cnt[v]++;
	}

	for(i=0;i<=V;i++)
	{
		edge[i] = (Edge *)malloc(sizeof(Edge) * cnt[i]);
		cnt[i] = 0;
	}

	for(i=0;i<2*E;i++)
	{
		int s = l[i].u;
		edge[s][cnt[s]] = (Edge) { l[i].v, l[i].w };
		cnt[s]++;
	}

	//1에서 V1까지, V2까지의 거리를 저장
	int V1_dist = dijest(1,V1);
	int V2_dist = dist[V2];

	//V1에서 V2까지, V1에서 V까지 저장
	V1_dist += dijest(V1, V2);
	V2_dist += dist[V];

	V2_dist += dijest(V2, V1);
	V1_dist += dist[V];

	if(V1_dist >= MAX && V2_dist >= MAX)
		printf("-1\n");
	else
	printf("%d\n", V2_dist < V1_dist ? V2_dist : V1_dist);

	return 0;
}
