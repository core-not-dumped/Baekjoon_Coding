#include <stdio.h>

void swap(int *arr,int a, int b)
{
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}
 
void myQuickSort(int *arr, int start, int end)
{
    int pivot = arr[start];
    int left = start+1;
    int right = end;
 
    while(left <= right)
	{
        while(arr[left] < pivot)	left++;
        while(arr[right] > pivot)	right--;
        if(left <= right)	swap(arr, left, right);
    }
 
 
    if(start < end)
	{
        swap(arr, start, right);
 
        myQuickSort(arr, start, right-1);
        myQuickSort(arr, right+1, end);
    }
 
    return;
}

int main(void)
{
	int N;
	scanf("%d", &N);

	int num[1001];
	int i;
	for(i=0;i<N;i++)
		scanf("%d", &num[i]);

	myQuickSort(num,0,N-1);

	for(i=0;i<N;i++)
		printf("%d\n", num[i]);
}
