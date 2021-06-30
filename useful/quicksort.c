#include <stdio.h>

// 오름차순으로 정렬해준다.
// while(arr[left] < pivot)	left++;
// while(arr[right] > pivot)	right--;
// 위 두 문장에서 부등호를 반대방향으로 바꿔주면 내림차순이다.

void Qsort(int *arr, int start, int end)
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
            tmp = arr[left];
            arr[left] = arr[right];
            arr[right] = tmp;
        }
    }
 
    if(start < end)
    {
        tmp = arr[start];
        arr[start] = arr[right];
        arr[right] = tmp; 

        Qsort(arr, start, right-1);
        Qsort(arr, right+1, end);
    }
 
    return;
}

int main(void)
{
	int num[1000000];
	int N;
	scanf("%d", &N);
	return 0;
}
