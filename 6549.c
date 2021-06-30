#include <stdio.h>

int n;
int h[100001];
int tree[1000001];
long long ans;

int init(int node, int start, int end)
{
	if(start == end)	return tree[node] = start;
	else
	{
		int half = (start + end)/2;
		int leftsmall = init(node*2, start, half);
		int rightsmall = init(node*2+1, half+1, end);
		return tree[node] = h[leftsmall] < h[rightsmall] ? leftsmall : rightsmall;
	}
}

int small(int node, int start, int end, int left, int right)
{
	if(end < left || start > right)		return 100000;
	if(start >= left && end <= right)	return tree[node];

	int half = (start + end) / 2;
	int leftsmall = small(node*2, start, half, left, right);
	int rightsmall = small(node*2+1, half+1, end, left, right);
	return h[leftsmall] < h[rightsmall] ? leftsmall : rightsmall;
}
 
void his(int s, int e)
{
	if(s >= e)	return;
	if(s+1 == e)
	{
		if(ans < h[s])	ans = h[s];
		return;
	}
	
	int ind = small(1,0,n-1,s,e-1);
	int min = h[ind];

	if(ans < (long long)min * (long long)(e - s))
		ans = (long long)min * (long long)(e - s);
		
	his(s,ind);
	his(ind+1,e);
}

int main(void)
{	
	h[100000] = 2100000000;
	while(1)
	{
		scanf("%d", &n);
		if(!n)	return 0;
		
		int i;
		for(i=0;i<n;i++)
			scanf("%d", &h[i]);

		init(1,0,n-1);

		ans = 0;	
		his(0, n);
		
		printf("%lld\n", ans);
	}
	return 0;
}
