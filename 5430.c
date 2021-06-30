#include <stdio.h>
#include <string.h>

int main(void)
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int num;
		char p[100001];
		scanf("%s %d", p, &num);

		int i;
		int x[100000];
		scanf("%*c");
		if(num == 0)	scanf("%*c");
		for(i=0;i<num;i++)
			scanf("%*c%d", &x[i]);
		scanf("%*c");

		int reverse = 0, r = 0, f = num;
		i = 0;
		while(p[i] != '\0')
		{
			if(p[i] == 'R')	reverse = !reverse;
			else
			{
				if(r == f)
				{
					printf("error\n");
					goto next;
				}
				if(!reverse)	r++;
				else	f--;
			}
			i++;
		}

		printf("[");
		if(!reverse)
		{
			for(i=r;i<f-1;i++)
				printf("%d,", x[i]);
		}
		else
		{
			for(i=f-1;i>r;i--)
				printf("%d,", x[i]);
		}
		if(r != f)	printf("%d", x[i]);
		printf("]\n");
		
		next:	continue;
	}

	return 0;
}
