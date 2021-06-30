#include <stdio.h>
#include <memory.h>
#include <string.h>

int main(void)
{
	int N;
	scanf("%d", &N);
	
	int i,j;
	char st[100];
	int plus;
	int ans;
	for(i=0;i<N;i++)
	{
		memset(st,0,sizeof(st));
		ans = 0;
		plus = 0;

		scanf("%s", st);

		for(j=0;j<((int)strlen(st));j++)
		{
			if(st[j] == 'O')	ans += ++plus;
			else	plus = 0;
		}

		printf("%d\n", ans);
	}


	return 0;
}
