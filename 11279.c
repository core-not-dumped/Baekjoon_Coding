#include <stdio.h>

int heap[100000];
int heap_size;

int is_empty()
{
	if(!heap_size)	return 1;
	else	return 0;
}

void insert_max_heap(int num)
{
	int cur = ++heap_size;
	while(cur != 1)
	{
		if(heap[cur/2] < num)
			heap[cur] = heap[cur/2];
		else	break;
		cur /= 2;
	}
	heap[cur] = num;
}

int delete_max_heap(void)
{
	int item = heap[1];
	int tmp = heap[heap_size--];
	int cur = 2;
	while(cur <= heap_size)
	{
		int maxind = heap[cur] > heap[cur+1] ? cur : cur+1;

		if(heap[maxind] > tmp)	heap[cur/2] = heap[maxind];
		else					break;

		cur = maxind * 2;
	}
	heap[cur/2] = tmp;

	return item;	
}

int main(void)
{
	int N;
	scanf("%d", &N);
	
	int i;
	int num;
	heap_size = 0;
	for(i=0;i<N;i++)
	{
		scanf("%d", &num);
		if(num)	insert_max_heap(num);
		else
		{
			if(is_empty())	printf("0\n");
			else
				printf("%d\n", delete_max_heap());
		}
	}

	return 0;
}
