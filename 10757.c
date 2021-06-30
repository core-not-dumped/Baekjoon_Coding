#include <stdio.h>
#include <string.h>

int main(void)
{
	char num1[10001], num2[10001], tmpnum[10001];
	scanf("%s", num1);
	scanf("%s", num2);

	int len1 = strlen(num1);
	int len2 = strlen(num2);
	int tmp;

	if(len1 < len2)
	{
		tmp = len1;
		len1 = len2;
		len2 = tmp;

		strcpy(tmpnum, num1);
		strcpy(num1, num2);
		strcpy(num2, tmpnum);
	}

	int i;
	int n1, n2, c, p;
	c = 0;
	for(i=1;i<len1+1;i++)
	{
		n1 = num1[len1 - i] - 48;
		n2 = (len2 - i >= 0) ? num2[len2 - i] - 48 : 0;
		p = n1 + n2 + c;
		if(p >= 10)
		{
			p -= 10;
			c = 1;
		}
		else	c = 0;
		num1[len1 - i] = p + 48;
	}

	if(c == 1)	printf("1");
	printf("%s\n", num1);

	return 0;
}
