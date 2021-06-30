#include <stdio.h>

int p[1000001];
int rank[1000001];

int find(int a)
{
	if(p[a] == a)	return a;
	return p[a] = find(p[a]);
}

void uni(int a, int b)
{
	a = find(a);
	b = find(b);

	if(a == b)	return;

	int tmp;
	if(rank[a] > rank[b])
	{
		tmp = a;
		a = b;
		b = tmp;
	}

	p[a] = b;

	if(rank[a] == rank[b])
		++rank[b];
}

int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);

	int i;
	for(i=1;i<=n;i++)
	{
		p[i] = i;
		rank[i] = 1;
	}

	int u, a, b;
	for(i=0;i<m;i++)
	{
		scanf("%d %d %d", &u, &a, &b);
		if(u == 0)	uni(a, b);
		else
		{
			if(find(a) == find(b))	printf("YES\n");
			else	printf("NO\n");
		}
	}

	return 0;
}
