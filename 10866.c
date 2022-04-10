#include <stdio.h>

int main(void)
{
	int N;
	scanf("%d", &N);
	
	int d[30000];
	int r = 15000, f = 15001;
	
	while(N--)
	{
		char str[20];
		scanf("%s", str);
		
		if(str[0] == 'p' && str[1] == 'u' && str[5] == 'f')
			scanf("%d", &d[r--]);
		else if(str[0] == 'p' && str[1] == 'u' && str[5] == 'b')
			scanf("%d", &d[f++]);
		else if(str[0] == 'p' && str[1] == 'o' && str[4] == 'f')
		{
			if(r + 1 == f)	printf("-1\n");
			else	printf("%d\n", d[++r]);
		}
		else if(str[0] == 'p' && str[1] == 'o' && str[4] == 'b')
		{
			if(r + 1 == f)	printf("-1\n");
			else	printf("%d\n", d[--f]);
		}
		else if(str[0] == 's')
			printf("%d\n", f - r - 1);
		else if(str[0] == 'e')
		{
			if(r + 1 == f)	printf("1\n");
			else	printf("0\n");
		}
		else if(str[0] == 'f')
		{
			if(r + 1 == f)	printf("-1\n");
			else	printf("%d\n", d[r+1]);
		}
		else
		{
			if(r + 1 == f)	printf("-1\n");
			else	printf("%d\n", d[f-1]);
		}
	}
}
