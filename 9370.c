#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define MAX 9000000

int V, E, K;
int des[100];
int dist[2001];
int cnt[2001];
int heap_size;

typedef struct Line{
	int u, v, w;
}L;
L l[100002];

typedef struct e{
	int v, w;
}Edge;
Edge *edge[2001];

struct h{
	int d, i;
}heap[30000];


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

int comp(const void *A, const void *B)
{
	return *(int *)A - *(int *)B;
}

int main(void)
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int t;
		scanf("%d %d %d", &V, &E, &t);

		int s, g, h;
		scanf("%d %d %d", &s, &g, &h);
	
		int i, j, g_to_h;
		memset(cnt,0,sizeof(cnt));
		for(i=0;i<E;i++)
		{
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			if(u == g && v == h)	g_to_h = w;
			if(u == h && v == g)	g_to_h = w;
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

		for(i=0;i<t;i++)
		scanf("%d", &des[i]);
		qsort(des,t,sizeof(int),comp);

		int sh_dist[100];
		int gh_dist[2][100];
		gh_dist[0][0] = dijest(s,g);
		for(i=1;i<t;i++)	gh_dist[0][i] = dist[g];
		for(i=0;i<t;i++)	gh_dist[1][i] = dist[h];
		for(i=0;i<t;i++)	sh_dist[i] = dist[des[i]];

		for(i=0;i<t;i++)	gh_dist[0][i] += g_to_h;
		for(i=0;i<t;i++)	gh_dist[1][i] += g_to_h;

		gh_dist[0][0] += dijest(h, des[0]);
		for(i=1;i<t;i++)	gh_dist[0][i] += dist[des[i]];

		gh_dist[1][0] += dijest(g, des[0]);
		for(i=1;i<t;i++)	gh_dist[1][i] += dist[des[i]];

		for(i=0;i<t;i++)
		{
			if(gh_dist[0][i] == sh_dist[i] || gh_dist[1][i] == sh_dist[i])
			printf("%d ", des[i]);
		}
		printf("\n");
	}

	return 0;
}
