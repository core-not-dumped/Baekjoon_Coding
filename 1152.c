#include <stdio.h>
#include <string.h>
#include <memory.h>

int main(void)
{
	char s[1000001];
	memset(s,0,sizeof(s));
	fgets(s, sizeof(s), stdin);

	int num = 0;
	int i;
	int l = strlen(s);
	
	if(l == 2 && s[0] == 32)
	{
		printf("0\n");
		return 0;
	}

	for(i=0;i<l;i++)
	{
		if(s[i]==32)
		{
			if(i>0 && i<l-2)	num++;
		}
	}
	
	printf("%d\n", num+1);
	return 0;
}
