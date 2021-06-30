#include <stdio.h>

#define MAX_SIZE 100

typedef struct priority_queue
{
	int Heap[MAX_SIZE];
	int Size;
}Queue;

Queue q;

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void initq(void)
{
	q.Size = 0;
}
 
int push(int value)
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
 
int pop()
{
    if (q.Size <= 0) return -1;
 
    int ret = q.Heap[0];
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
 
int empty() {
    if (q.Size == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

int main(void)
{
	int N;

	scanf("%d", &N);

	for (int i=0;i<N;i++)
	{
		int value;
		scanf("%d", &value);
		push(value);
	}

	//initq();

	while(!empty()) printf("%d ", pop());

	printf("\n");

	return 0;
}
