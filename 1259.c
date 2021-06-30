#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[6];
	while(1)
	{
		scanf("%s", str);
		if(str[0] == '0')	return 0;
		
		int l = strlen(str);
		int i;
		for(i=0;i<l/2;i++)
		{
			if(str[i] == str[l-i-1])
				continue;
			else	break;
		}
		if(i == l/2)	printf("yes\n");
		else	printf("no\n");
	}
}
