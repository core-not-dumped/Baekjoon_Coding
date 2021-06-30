#include <stdio.h>
#include <stdlib.h>

int comp(const void *A, const void *B)
{
	if(*(int *)A < *(int *)B)	return -1;
	if(*(int *)A > *(int *)B)	return 1;
	else	return 0;
}

int BSearch(int arr[], int target, int low, int high)
{
	if (low > high)	return 0;

	int mid = (low + high) / 2;
	if(arr[mid] == target)	return 1;

	else if (arr[mid] > target)
		return BSearch(arr, target, low, mid-1);
	else
		return BSearch(arr, target, mid+1, high);
}

int main(void)
{
	int N;
	scanf("%d", &N);

	int i;
	int a[100000];
	for(i=0;i<N;i++)
		scanf("%d", &a[i]);

	qsort(a,N,sizeof(int),comp);

	int M;
	scanf("%d", &M);
	for(i=0;i<M;i++)
	{
		int num;
		scanf("%d", &num);
		printf("%d\n", BSearch(a,num,0,N-1));
	}

	return 0;
}
