#include <stdio.h>
#include <string.h>

int main(void)
{
	int N;
	scanf("%d", &N);

	char com[20];
	int st[10000];
	int sp = 0;
	int i;
	for(i=0;i<N;i++)
	{
		memset(com,0,sizeof(com));
		scanf("%s", com);

		if(com[0] == 's')	printf("%d\n", sp);
		else if(com[0] == 't')
		{
			if(sp == 0)	printf("-1\n");
			else	printf("%d\n", st[sp-1]);
		}
		else if(com[0] == 'e')
		{
			if(sp == 0)	printf("1\n");
			else	printf("0\n");
		}
		else
		{
			if(com[1] == 'o')
			{
				if(sp == 0)	printf("-1\n");
				else	printf("%d\n", st[--sp]);
			}
			else
				scanf("%d", &st[sp++]);
		}
	}

	return 0;
}
