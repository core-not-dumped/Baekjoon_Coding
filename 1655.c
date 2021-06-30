#include <stdio.h>
int max_heap[100000];
int max_heap_size;
int min_heap[100000];
int min_heap_size;

void insert_max_heap(int num)
{
	int cur = ++max_heap_size;
	while(cur != 1)
	{
		if(max_heap[cur/2] < num)
			max_heap[cur] = max_heap[cur/2];
		else	break;
		cur /= 2;
	}
	max_heap[cur] = num;
}

int delete_max_heap(void)
{
	int item = max_heap[1];
	int tmp = max_heap[max_heap_size--];
	int cur = 2;
	while(cur <= max_heap_size)
	{
		int maxind = max_heap[cur] > max_heap[cur+1] ? cur : cur+1;

		if(max_heap[maxind] > tmp)	max_heap[cur/2] = max_heap[maxind];
		else						break;

		cur = maxind * 2;
	}
	max_heap[cur/2] = tmp;

	return item;	
}

void insert_min_heap(int num)
{
	int cur = ++min_heap_size;
	while(cur != 1)
	{
		if(min_heap[cur/2] > num)
			min_heap[cur] = min_heap[cur/2];
		else	break;
		cur /= 2;
	}
	min_heap[cur] = num;
}

int delete_min_heap(void)
{
	int item = min_heap[1];
	int tmp = min_heap[min_heap_size--];
	int cur = 2;
	while(cur <= min_heap_size)
	{
		int minind = min_heap[cur] < min_heap[cur+1] ? cur : cur+1;

		if(min_heap[minind] < tmp)	min_heap[cur/2] = min_heap[minind];
		else						break;

		cur = minind * 2;
	}
	min_heap[cur/2] = tmp;

	return item;	
}

int main(void)
{
	max_heap_size = 0;
	min_heap_size = 0;

	int N;
	scanf("%d", &N);

	int num;
	scanf("%d", &num);
	printf("%d\n", num);
	if(N == 1)	return 0;
	insert_max_heap(num);

	int i;
	for(i=1;i<N;i++)
	{
		scanf("%d", &num);
		if(!(i&1))
		{
			if(min_heap[1] < num)
			{
				insert_max_heap(delete_min_heap());
				insert_min_heap(num);
			}
			else	insert_max_heap(num);
		}
		else
		{
			if(max_heap[1] > num)
			{
				insert_min_heap(delete_max_heap());
				insert_max_heap(num);
			}
			else	insert_min_heap(num);
		}
		printf("%d\n", max_heap[1]);
	}

	return 0;
}
