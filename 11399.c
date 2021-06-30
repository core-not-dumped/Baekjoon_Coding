#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b)
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
	int n, p[1000];
	scanf("%d", &n);

	int i;
	for(i=0;i<n;i++)
		scanf("%d", &p[i]);

	qsort(p,n,sizeof(int),comp);

	int sum = 0;
	for(i=0;i<n;i++)
	{
		sum += p[i] * (n - i);
	}

	printf("%d\n", sum);

	return 0;
}
