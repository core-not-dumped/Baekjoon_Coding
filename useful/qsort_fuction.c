#include <stdio.h>
#include <stdlib.h>

//qsort 함수 사용법
//오름차순으로 정렬된다.

int compare(const void *a, const void *b)
{
	if(*(int *)a < *(int *)b)
		return -1;
	else if(*(int *)a > *(int *)b)
		return 1;
	else
		return 0;
}

int main(void)
{
	int N;
	int num[1000001];

	qsort(num, N, sizeof(int), compare);
}
