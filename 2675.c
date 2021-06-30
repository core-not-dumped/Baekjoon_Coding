#include <stdio.h>
#include <string.h>
#include <memory.h>

int main(void)
{
	int T, t;
	scanf("%d", &T);
	for(t=0;t<T;t++)
	{
		int R;
		scanf("%d", &R);
		
		char word[21];
		memset(word,0,sizeof(word));
		scanf("%s", word);

		int l = strlen(word);
		int i, j;
		for(i=0;i<l;i++)
		{
			for(j=0;j<R;j++)
				printf("%c", word[i]);
		}
		printf("\n");
	}

	return 0;
}
