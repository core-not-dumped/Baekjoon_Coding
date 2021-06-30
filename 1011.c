#include <stdio.h>

int main(void)
{
	int T, t;
	scanf("%d", &T);

	for(t=0;t<T;t++)
	{
		long long x,y;
		scanf("%lld %lld", &x, &y);
		long long d = y - x;
		
		if(d <= 3)	{ printf("%lld\n", d); continue; }
	
		long long ch = 1;
		int res = 0;
		while(1)
		{
			ch++;
			if(d <= ((ch-1) * ch))
				break;
			else if(d <= ch*ch)
			{
				res = 1;
				break;
			}
		}
		printf("%lld\n", ((ch-1)*2)+res);
	}

	return 0;
}
