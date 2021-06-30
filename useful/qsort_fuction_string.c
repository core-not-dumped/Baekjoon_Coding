#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
	return strcmp((char *)a, (char *)b);
}

int main(void)
{
	int N;
	scanf("%d", &N);

	int i;
	char s[100][100];
	for(i=0;i<N;i++)
		scanf("%s", s[i]);

	qsort(s, N, sizeof(s[0]), compare);

	for(i=0;i<N;i++)
		printf("%s\n", s[i]);
	printf("\n");

	return 0;
}
