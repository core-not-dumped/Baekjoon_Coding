#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
	if(*(int *)a > *(int *)b)
		return 1;
	else if(*(int *)a < *(int *)b)
		return -1;
	else
		return 0;
}

int main(void)
{
	int N;
	scanf("%d", &N);

	int num[1000001];
	int i, j;
	for(i=0;i<N;i++)
		scanf("%d", &num[i]);

	qsort(num, N, sizeof(int), compare);

	for(i=0;i<N;i++)
		printf("%d\n", num[i]);
}
