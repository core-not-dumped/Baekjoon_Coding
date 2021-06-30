#include <stdio.h>

#define MAX_SIZE 1000

typedef struct priority_queue
{
	long long Heap[MAX_SIZE];
	int Size;
}Queue;

Queue q;

void swap(long long *a, long long *b)
{
    long long tmp = *a;
    *a = *b;
    *b = tmp;
}
 
int push(long long value)
{
    if (q.Size + 1 > MAX_SIZE)	return 0;
 
    q.Heap[q.Size] = value;
 
    int current = q.Size;
    int parent = (q.Size - 1) / 2;
 
    while (current > 0 && q.Heap[current] < q.Heap[parent])
	{
        swap(&q.Heap[current], &q.Heap[parent]);
        current = parent;
        parent = (parent - 1) / 2;
    }
 
    q.Size++;
 
    return 1;
}
 
long long pop()
{
    if (q.Size <= 0) return -1;
 
    long long ret = q.Heap[0];
    q.Size--;
 
    q.Heap[0] = q.Heap[q.Size];
    int current = 0;
    int leftChild = current * 2 + 1;
    int rightChild = current * 2 + 2;
    int maxNode = current;
 
    while (leftChild < q.Size)
	{
        if (q.Heap[maxNode] > q.Heap[leftChild])
            maxNode = leftChild;
        if (rightChild < q.Size && q.Heap[maxNode] > q.Heap[rightChild])
            maxNode = rightChild;
 
        if (maxNode == current)
            break;
        else {
            swap(&q.Heap[current], &q.Heap[maxNode]);
            current = maxNode;
            leftChild = current * 2 + 1;
            rightChild = current * 2 + 2;
        }
    }
        
    return ret;
}

int main(void)
{
	int mod = 1e9+7;
	int T;
	int test;
	scanf("%d", &T);
	for(test=0;test<T;test++)
	{
		int N;
		scanf("%d", &N);
		
		int i, j;
		long long C;
		for(i=0;i<N;i++)
		{
			scanf("%lld", &C);
			push(C);
		}
		
		long long min = 1;
		long long mul;
		for(i=0;i<N-1;i++)
		{
			mul = pop() * pop();
			min = min * (mul % mod) % mod;
			push(mul);
		}

		pop();
		printf("%lld\n", min);
	}

	return 0;
}
