#include <stdio.h>

int BSearch(int arr[], int target, int low, int high)
{
	int mid;

	while(low <= high)
	{
		mid = (low + high) / 2;
		
		if(arr[mid] == target)
			return mid;
		else if (arr[mid] > target)
			high = mid - 1;
		else
			low = mid + 1;
	}
	
	return -1;
}

int BSearchRecursive(int arr[], int target, int low, int high)
{
	if (low > high)	return -1;

	int mid = (low + high) / 2;
	if(arr[mid] == target)
		return mid;

	else if (arr[mid] > target)
		return BSearchRecursive(arr, target, low, mid-1);
	else
		return BSearchRecursive(arr, target, mid+1, high);
}

int main(void)
{
	int a[10] = {2, 34, 65, 123, 674, 1234, 5633, 42323, 361235, 1232133};

	//배열, 찾는 값, 배열의 시작, 배열의 끝
	int search1 = BSearch(a, 674, 0, 9);
	int search2 = BSearchRecursive(a, 674, 0, 9);

	printf("%d %d\n", search1, search2);
	return 0;
}
