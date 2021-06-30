#include <stdio.h>

int main(void)
{
	int n;
	scanf("%d", &n);
	
	int q[20000];
	int r = 0, f = 0;
	
	while(n--)
	{
		char com[10];
		scanf("%s", com);
		
		if(com[0] == 'p')
		{
			if(com[1] == 'u')
			{
				int num;
				scanf("%d", &num);
				q[f++] = num;
			}
			else
			{
				if(r == f)	printf("-1\n");
				else	printf("%d\n", q[r++]);
			}
		}
		
		if(com[0] == 's')
		{
			printf("%d\n", f - r);
		}
		
		if(com[0] == 'e')
		{
			if(r == f)	printf("1\n");
			else		printf("0\n");
		}
		
		else if(com[0] == 'f')
		{
			if(r == f)	printf("-1\n");
			else		printf("%d\n", q[r]);
		}
		
		else if(com[0] == 'b')
		{
			if(r == f)	printf("-1\n");
			else		printf("%d\n", q[f-1]);
		}
	}
	
	return 0;
}
