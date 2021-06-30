#include <stdio.h>
#include <string.h>

int chnum(char a)
{
	if(a <= 67)	return 2;
	if(a <= 70)	return 3;
	if(a <= 73)	return 4;
	if(a <= 76)	return 5;
	if(a <= 79)	return 6;
	if(a <= 83)	return 7;
	if(a <= 86)	return 8;
	if(a <= 90)	return 9;
}

int main(void)
{
	char w[20];
	scanf("%s", w);

	int i;	
	int sum = 0;
	for(i=0;i<strlen(w);i++)
		sum += chnum(w[i])+1;

	printf("%d\n", sum);

	return 0;
}
