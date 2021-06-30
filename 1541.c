#include <stdio.h>
#include <string.h>

char str[50];
int pt;

int n(void)
{
	int num = 0;
	for(;;pt++)
	{
		if(str[pt] >= 48 && str[pt] <= 57)
		{
			num *= 10;
			num += str[pt] - 48;
		}
		else	break;
	}

	return num;
}

int main(void)
{
	scanf("%s", str);

	int num[50];
	char op[50];
	int nump = 0;
	while(1)
	{
		num[nump] = n();
		if(pt >= strlen(str))	break;
		op[nump++] = str[pt];
		pt++;
	}

	int i;
	int sum = num[0];
	for(i=0;i<nump;i++)
	{
		if(op[i] == '+')	sum += num[i+1];
		else	break;
	}
	for(;i<nump;i++)
		sum -= num[i+1];

	printf("%d\n", sum);

	return 0;
}
