#include <stdio.h>
#include <string.h>

int main(void)
{
	while(1)
	{
		char str[10];
		scanf("%s", str);
		if(str[0] == '#')	return 0;
		
		char s[10] = {'-', '\\', '(', '@', '?', '>', '&','%', '/'};
		int num = 1, i, j, ans = 0;
		for(i=strlen(str)-1;i>=0;i--)
		{
			for(j=0;j<9;j++)
			{
				if(str[i] == s[j])	break;
			}
			if(j == 8)	j = -1;
			ans += num * j;
			num *= 8;
		}
		printf("%d\n", ans);
	}
}
