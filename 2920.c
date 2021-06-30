#include <stdio.h>

int main(void)
{
	int i, c = 0;
	int a[8];
	for(i=0;i<8;i++)
	{
		scanf("%d", &a[i]);
		if(i) c+=a[i]>a[i-1];
	}
	
	puts(c-7?c?"mixed":"descending":"ascending");
	
	return 0;
}
