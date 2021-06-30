#include <stdio.h>
#include <memory.h>

int main(void)
{
	int N;
	scanf("%d", &N);

	char w[101];
	int num = 0;
	int i,j;
	for(i=0;i<N;i++)
	{
		memset(w,0,sizeof(w));
		scanf("%s", w);

		int alpha[27];
		char b = 0;
		memset(alpha,0,sizeof(alpha));
		for(j=0;j<strlen(w);j++)
		{
			if(w[j] == b)	continue;
			if(alpha[w[j]-97] == 1)	break;
			else
			{
				alpha[w[j]-97] = 1;
				b = w[j];
			}
		}
		if(j == strlen(w))	num++;
	}

	printf("%d\n", num);

	return 0;
}
