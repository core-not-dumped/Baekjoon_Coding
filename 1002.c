#include <stdio.h>
#include <math.h>

int main(void)
{
	int T,t;
	scanf("%d", &T);
	for(t=0;t<T;t++)
	{
		int x1, y1, r1, x2, y2, r2;
		scanf("%d %d %d", &x1, &y1, &r1);
		scanf("%d %d %d", &x2, &y2, &r2);
		if(x1 == x2 && y1 == y2 && r1 == r2)
		{
			printf("-1\n");
			continue;
		}

		double d1;
		d1 = sqrt((double)((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)));

		if((d1+r2) < r1)	printf("0\n");
		else if((d1+r2) == r1)	printf("1\n");
		else if((d1+r1) < r2)	printf("0\n");
		else if((d1+r1) == r2)	printf("1\n");
		else if(d1 == (r1+r2))	printf("1\n");
		else if(d1 > (r1+r2))	printf("0\n");
		else if(d1 < (r1+r2))	printf("2\n");
	}

	return 0;
}
