#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
	if(strlen((char *)a) > strlen((char *)b))
		return 1;
	if(strlen((char *)a) < strlen((char *)b))
		return -1;
	if(strlen((char *)a) == strlen((char *)b))
	{
		return strcmp((char *)a, (char *)b);
	}
}

int main(void)
{
	int N;
	scanf("%d", &N);

	int i;
	char s[20001][51];
	for(i=0;i<N;i++)
		scanf("%s", s[i]);

	qsort(s, N, sizeof(s[0]), compare);

	printf("%s\n", s[0]);
	for(i=1;i<N;i++)
	{
		if(strcmp(s[i], s[i-1]))
			printf("%s\n", s[i]);
	}

	return 0;
}
