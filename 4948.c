#include <stdio.h>

int main()
{
	int i,j,ch[250000] = {1,1,};
	for(i=2;i<250000;i++)
	{
		if(!ch[i])
		{
			for(j=2*i;j<250000;j+=i)
				ch[j] = 1;
		}
	}

	while(1)
	{
		int n, ans = 0;
		scanf("%d", &n);

		if(!n)	return 0;

		for(i=n+1;i<=2*n;i++)
			ch[i] ? : ans++;

		printf("%d\n", ans);
	}
}
