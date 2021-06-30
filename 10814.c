#include <stdio.h>
#include <string.h>

char name[100001][101];

void Qsort(int *arr, int *subarr, int start, int end)
{
    int pivot = arr[start];
    int left = start+1;
    int right = end;
    int tmp;
	char tmparr[101];
 
    while(left <= right)
	{
        while(arr[left] <= pivot)	left++;
        while(arr[right] > pivot)	right--;
        if(left <= right)
        {
            tmp = arr[left];
            arr[left] = arr[right];
            arr[right] = tmp;

			tmp = subarr[left];
			subarr[left] = subarr[right];
			subarr[right] = tmp;

			strcpy(tmparr, name[left]);
			strcpy(name[left], name[right]);
			strcpy(name[right], tmparr);
        }
    }
 
    if(start < end)
    {
        tmp = arr[start];
        arr[start] = arr[right];
        arr[right] = tmp; 

		tmp = subarr[start];
		subarr[start] = subarr[right];
		subarr[right] = tmp;

		strcpy(tmparr, name[start]);
		strcpy(name[start], name[right]);
		strcpy(name[right], tmparr);

        Qsort(arr, subarr, start, right-1);
        Qsort(arr, subarr, right+1, end);
    }
 
    return;
}

int main(void)
{
	int N;
	scanf("%d", &N);

	int age[100001];

	int ch[100001];
	int i;
	for(i=0;i<N;i++)
	{
		scanf("%d %s", &age[i], name[i]);
		ch[i] = i;
	}

	Qsort(age, ch, 0, N-1);

	int num = 0;
	for(i=0;i<N;i++)
	{
		if(age[i] == age[i+1])	num++;
		else
		{
			Qsort(ch, age, i-num, i);
			num = 0;
		}
	}

	for(i=0;i<N;i++)
		printf("%d %s\n", age[i], name[i]);

	return 0;
}
