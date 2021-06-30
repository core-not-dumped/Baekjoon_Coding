#include <stdio.h>
#include <string.h>

int main(void)
{
	char w[101];
	scanf("%s", w);

	int i;
	int num = 0;
	for(i=0;i<strlen(w);i++)
	{
		if(w[i] == 'c')
		{
			if(w[i+1] == '=' || w[i+1] == '-')
			{
				i++;
				num++;
			}
		}
		else if(w[i] == 'd')
		{
			if(w[i+1] == '-')
			{
				i++;
				num++;
			}
			else if(w[i+1] == 'z')
			{
				if(w[i+2] == '=')
				{
					i += 2;
					num += 2;
				}
			}
		}
		else if(w[i] == 'l')
		{
			if(w[i+1] == 'j')
			{
				i++;
				num++;
			}
		}
		else if(w[i] == 'n')
		{
			if(w[i+1] == 'j')
			{
				i++;
				num++;
			}
		}
		else if(w[i] == 's')
		{
			if(w[i+1] == '=')
			{
				i++;
				num++;
			}
		}
		else if(w[i] == 'z')
		{
			if(w[i+1] == '=')
			{
				i++;
				num++;
			}
		}
	}

	printf("%d\n", (int)strlen(w)-num);

	return 0;
}
