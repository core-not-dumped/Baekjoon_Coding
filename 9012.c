#include <stdio.h>
#include <string.h>

int main(void)
{
	int N;
	scanf("%d", &N);
	
	while(N--)
	{
		char g[51];
		scanf("%s", g);
		
		int i;
		int p = 0;
		for(i=0;i<strlen(g);i++)
		{
			if(g[i] == '(')	p++;
			else	p--;
			
			if(p < 0)
			{
				printf("NO\n");
				break;
			}
		}
		
		if(i == strlen(g))
		{
			if(p == 0)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	
	return 0;
}
