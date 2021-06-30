#include <stdio.h>

int swap(int *a,int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main(void)
{
	int a, b, c;
	while(1)
	{
		scanf("%d %d %d", &a, &b, &c);
		if((!a) && (!b) && (!c))	return 0;

		if(a>c)	swap(&a,&c);
		if(b>c)	swap(&b,&c);
	
		if((a*a+b*b) == (c*c))	printf("right\n");
		else	printf("wrong\n");
	}

	return 0;
}
