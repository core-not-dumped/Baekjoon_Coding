#include <stdio.h>
#include <memory.h>

int d(int n)
{
	int i;
	int sum = n;
	int res;
	while(n>0)
	{
		res = n%10;
		n /= 10;
		sum += res;
	}

	return sum;
}

int main(void)
{
	int i;
	int sn[10002];
	memset(sn,0,sizeof(sn));
	
	int tmp;
	for(i=1;i<10001;i++)
	{
		if(sn[i])	continue;

		tmp = i;
		while(tmp < 10001)
		{
			sn[tmp] = 1;
			tmp = d(tmp);
		}
		sn[i] = 0;
	}

	for(i=1;i<10001;i++)
	{
		if(!sn[i])
			printf("%d\n", i);
	}

	return 0;
}
