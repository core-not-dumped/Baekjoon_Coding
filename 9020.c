#include <stdio.h>

int main()
{
	int i,j,ch[10001] = {1,1,};
	for(i=2;i<10001;i++)
	{
		if(!ch[i])
		{
			for(j=2*i;j<10001;j+=i)
				ch[j] = 1;
		}
	}
	
	int T,t;
	scanf("%d", &T);
	for(t=0;t<T;t++)
	{
		int n;
		scanf("%d", &n);

		int h;
		for(h=n/2;h<n;h++)
		{
			if((!ch[h]) && (!ch[n-h]))
			{
				printf("%d %d\n", n-h, h);
				break;
			}
		}
	}
}
