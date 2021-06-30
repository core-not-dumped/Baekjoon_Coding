// 필요한 노드 수는 2N-1개
// 하지만 tree는 더 많은 메모리를 요구한다. 

#include <stdio.h>

long long a[100000];
long long tree[1000000];

long long init(int node, int start, int end)
{

	if(start == end)	return tree[node] = a[start];
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
 
// diff는longlong 이어야 바꿀때 제대로 된 값이 들어간다. 
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
	int N;
	scanf("%d", &N);
	
	int i;
	for(i=0;i<N;i++)
		scanf("%d", &a[i]);
	
	// 0부터 N-1까지 포함한 것을 세그먼트 트리에 넣는다. 
	init(1,0,N-1);
	
	for(i=0;i<50;i++)
	printf("%d ", tree[i]);
	printf("\n");
	
	// 1번노드는 0~N-1까지의 합이고
	// 0~9번째까지의 합을 출 
	printf("%d\n", sum(1, 0, N-1, 0, 9)); 

	// 1번노드는 0~N-1의 값을 가지고 있고
	// 3번째노드(0이첫번째)에 3을 더하라. 
	update(1,0,N-1,3,3);
	//tree를 업데이트 시키고 a안의 값도 바꾸어줘야 한다. 
	a[3] = 3;

	for(i=0;i<50;i++)
	printf("%d ", tree[i]);
	printf("\n");
	
	return 0;
}
