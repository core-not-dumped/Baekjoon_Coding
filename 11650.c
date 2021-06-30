#include <stdio.h>


void swap(int *arr, int a, int b)
{
	int tmp;
	tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}

void Qsort(int *arr, int *subarr, int start, int end)
{
    int pivot = arr[start];
    int left = start+1;
    int right = end;
    int tmp;
 
    while(left <= right)
	{
        while(arr[left] <= pivot)	left++;
        while(arr[right] > pivot)	right--;
        if(left <= right)
		{
			swap(arr, left, right);
			swap(subarr, left, right);
		}
    }
 
    if(start < end)
    {
        swap(arr, start, right);
        swap(subarr, start, right);

        Qsort(arr, subarr, start, right-1);
        Qsort(arr, subarr, right+1, end);
    }
 
    return;
}

int main(void)
{
	int N;
	scanf("%d", &N);

	int x[100001], y[100001];
	int i;
	for(i=0;i<N;i++)
		scanf("%d %d", &x[i], &y[i]);

	Qsort(x, y, 0, N-1);

	int num = 0;
	for(i=0;i<N;i++)
	{
		if(x[i] == x[i+1])	num++;
		else
		{
			if(num >= 1)
			{
				Qsort(y, x, i-num, i);
				num = 0;
			}
		}
	}

	for(i=0;i<N;i++)
		printf("%d %d\n", x[i], y[i]);

	return 0;
}
