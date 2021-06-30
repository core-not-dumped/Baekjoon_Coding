#include <stdio.h>
#include <string.h>
#include <memory.h>

int main(void)
{
	int alpha[27];
	char word[101];
	scanf("%s", word);
	memset(alpha, -1, sizeof(alpha));

	int i, l = strlen(word);
	for(i=0;i<l;i++)
	{
		if(alpha[word[i]-97] == -1)
			alpha[word[i]-97] = i;
	}

	for(i=0;i<26;i++)
		printf("%d ", alpha[i]);
	printf("\n");

	return 0;
}
