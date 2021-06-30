#include <stdio.h>

long long a[1000000];
long long tree[2500000];

long long init(node, start, end)
{
	if(start == end)
		return tree[node] = a[start];
	else
	{
		int half = (start + end)/2;
		return tree[node] = init(node*2, start, half) + init(node*2+1, half+1, end);
	}
}

long long sum(int node, int start, int end, int left, int right)
{
	if(end < left || start > right)		return 0;
	if(start >= left && end <= right)	return tree[node];
	 
	int half = (start + end) / 2;
	return sum(node*2, start, half, left, right) + sum(node*2+1, half+1, end, left, right);
}

void update(int node, int start, int end, int index, long long diff)
{
	if(start > index || end < index)	return;
	tree[node] += diff;
	if(start != end)
	{
		int half = (start + end) / 2;
		update(node*2, start, half, index, diff);
		update(node*2+1, half+1, end, index, diff);
	}
}

int main(void)
{
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	
	int i;
	for(i=0;i<N;i++)
		scanf("%d", &a[i]);
		
	init(1, 0, N-1);
	
	for(i=0;i<M+K;i++)
	{
		int A, B;
		long long C;
		scanf("%d %d %lld", &A, &B, &C);
		
		if(A == 1)
		{
			update(1,0,N-1,B-1,C-a[B-1]);
			a[B-1] = C;
		}
		else
			printf("%lld\n", sum(1,0,N-1,B-1,C-1));
	}
	
	return 0;
}
