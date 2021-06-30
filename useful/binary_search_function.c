// 반드시 배열이 오름차순으로 정렬되어있어야 한다.
#include <stdio.h>
#include <stdlib.h>

int compare(const void *first, const void *second)
{
	if(*(int *)first < *(int *)second)	return -1;
	if(*(int *)first > *(int *)second)	return 1;
	else	return 0;
}

int main(void)
{
	int N;
	scanf("%d", &N);

	int i;
	int arr[100];
	for(i=0;i<N;i++)
		scanf("%d", &arr[i]);

	int key;
	int *find;
	while(1)
	{
		scanf("%d", &key);
		/////////// 함수 사용 /////////////////////////////
		find = bsearch(&key, arr, N, sizeof(int), compare);
		/////////// 함수 사용 /////////////////////////////
		if(find != NULL)
			printf("Find value: %d\n", *find);
		else
			printf("Can't Find\n");
	}

	return 0;
}

