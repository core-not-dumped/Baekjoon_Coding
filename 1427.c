#include <stdio.h>
#include <memory.h>
#include <string.h>

void Qsort(char *arr, int start, int end)
{
    char pivot = arr[start];
    int left = start+1;
    int right = end;
    char tmp;
 
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
	char N[20];
	memset(N,0,sizeof(N));
	scanf("%s", N);

	Qsort(N,0,(int)strlen(N)-1);

	int t = 1;
	int num = 0;
	int i;
	for(i=0;i<(int)strlen(N);i++)
	{
		num += (N[i] - 48) * t;
		t *= 10;
	}
	
	printf("%d\n", num);
}
