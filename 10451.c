#include <stdio.h>

int main(void)
{
	int T, t;
	scanf("%d", &T);
	for(t=0;t<T;t++)
	{
		int N, i;
		scanf("%d", &N);

		int line[1002];
		for(i=0;i<N;i++)
			scanf("%d", &line[i+1]);

		int ch[1002];
		int spot;
		int cycle = 0;
		for(i=0;i<1001;i++)
			ch[i] = 0;
		for(i=1;i<N+1;i++)
		{
			if(ch[i] == 0)
			{
				cycle++;
				ch[i] = cycle;
				spot = i;
				while(ch[line[spot]] == 0)
				{
					ch[line[spot]] = cycle;
					spot = line[spot];
				}
			}
		}

		printf("%d\n", cycle);
	}
	
	return 0;
}
