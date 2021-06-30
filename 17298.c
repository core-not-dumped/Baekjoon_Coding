#include <stdio.h>

int main(void)
{
	int n;
	scanf("%d", &n);
	
	int i;
	int a[1000000];
	for(i=0;i<n;i++)
		scanf("%d", &a[i]);
	
	int p[1000000];
	int j;
	int stack[1000000];
	int sp = 0;
	for(i=0;i<n;i++)
	{
		for(j=sp-1;j>=0;j--)
		{
			if(a[stack[j]] < a[i])
			{
				p[stack[j]] = a[i];
				sp--;
			}
			else	break;
		}
		stack[sp++] = i;
	}
	
	for(i=0;i<sp;i++)
		p[stack[i]] = -1;
	
	for(i=0;i<n;i++)
		printf("%d ", p[i]);
	printf("\n");
	
	return 0;
}
