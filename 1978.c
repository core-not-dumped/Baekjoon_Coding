#include <stdio.h>
#include <memory.h>

int main(void)
{
	int N;
	scanf("%d", &N);

	int i;
	int num[101];
	for(i=0;i<N;i++)
		scanf("%d", &num[i]);

	int ch[1001];
	int tmp;
	memset(ch,0,sizeof(ch));
	ch[0] = 1;	ch[1] = 1;
	for(i=2;i<1001;i++)
	{
		if(ch[i] == 0)
		{
			tmp = 2 * i;
			while(tmp < 1001)
			{
				ch[tmp] = 1;
				tmp += i;
			}
		}
	}

	int re = 0;
	for(i=0;i<N;i++)
	{
		if(ch[num[i]] == 0)	re++;
	}

	printf("%d\n", re);

	return 0;
}
