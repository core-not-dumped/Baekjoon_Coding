#include <stdio.h>
#include <string.h>

int main(void)
{
	int t;
	scanf("%d", &t);
	
	while(t--)
	{
		int n;
		scanf("%d", &n);
		
		int i, j;
		char name[21], ktmp[21], k[30][21];
		int knum[30];
		int p = 0;
		
		memset(knum,0,sizeof(knum));
		
		for(i=0;i<n;i++)
		{
			scanf("%s", name);
			scanf("%s", ktmp);
			for(j=0;j<p;j++)
			{
				if(!strcmp(k[j],ktmp)) 
				{
					knum[j]++;
					break;
				}
			}
			 
			if(j == p)
			{
				knum[p]++;
				strcpy(k[p++], ktmp);
			}
		}
		
		int mul = 1;
		for(i=0;i<p;i++)
			mul *= knum[i]+1;	
		
		printf("%d\n", mul-1);
	}
	
	return 0;
}
