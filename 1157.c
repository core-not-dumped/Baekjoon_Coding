#include <stdio.h>
#include <string.h>
#include <memory.h>

int main(void)
{
	char word[1000001];
	int alpha[27];
	memset(alpha, 0, sizeof(alpha));

	scanf("%s", word);
	int l = strlen(word);

	int i;
	for(i=0;i<l;i++)
		alpha[(word[i] & 223) - 65]++;
	
	int max = 0;
	int index;
	for(i=0;i<26;i++)
	{
		if(!alpha[i])	continue;
		if(max == alpha[i])	index = 28;
		else if(max < alpha[i])
		{
			max = alpha[i];
			index = i;
		}
	}

	if(index == 28)	printf("?\n");
	else	printf("%c\n", index+65);

	return 0;
}
