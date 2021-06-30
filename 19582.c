#include <stdio.h>

void swap(int *arr,int a, int b)
{
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}
 
void QSort(int *arr, int *p, int start, int end)
{
    int pivot = arr[start];
    int left = start+1;
    int right = end;
 
    while(left <= right)
	{
        while(arr[left] < pivot)	left++;
        while(arr[right] > pivot)	right--;
 
        if(left <= right)
		{
			swap(p, left, right);
			swap(arr, left, right);
		}
    }
 
 
    if(start < end)
	{
        swap(arr, start, right);
		swap(p, start, right); 

        QSort(arr, p, start, right-1);
        QSort(arr, p, right+1, end);
    }
 
    return;
}

int main(void)
{
	int N;
	scanf("%d", &N);

	int x[100001], p[100001];
	int i;
	for(i=0;i<N;i++)
		scanf("%d %d", &x[i], &p[i]);

	QSort(x,p,0,N-1);

	for(i=0;i<N;i++)
	{
		printf("%d %d\n", x[i], p[i]);
	}

	return 0;
}
