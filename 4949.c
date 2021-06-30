#include <stdio.h>
#include <string.h>

int main(void)
{
	while(1)
	{
		char str[200];
		int i = 0;
		do {
    		str[i++] = getchar();
  		} while (str[i-1] != '\n');
		str[i] = '\0';
		
		if(str[0] == '.' && str[1] == '\n')	break;
		
		int stack[200];
		int p = 0;
		for(i=0;i<strlen(str);i++)
		{
			if(str[i] == '(')	stack[p++] = 1;
			else if(str[i] == ')')
			{
				if(p-1 >= 0)
				{
					if(stack[p-1] == 1)
						p--;
					else
					{
						printf("no\n");
						break;
					}
				}
				else
				{
					printf("no\n");
					break;
				}
			}
			else if(str[i] == '[')	stack[p++] = 2;
			else if(str[i] == ']')
			{
				if(p-1 >= 0)
				{
					if(stack[p-1] == 2)
						p--;
					else
					{
						printf("no\n");
						break;
					}
				}
				else
				{
					printf("no\n");
					break;
				}
			}
		}
		
		if(i == strlen(str))
		{
			if(p == 0)
				printf("yes\n");
			else
				printf("no\n");
		}
	}
	
	return 0;
}
