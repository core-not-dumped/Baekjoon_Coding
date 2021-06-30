#include <stdio.h>
#include <memory.h>

int main(void)
{
	int N;
	scanf("%d", &N);

	int ch[10002];
	memset(ch,0,sizeof(ch));

	int num;
	int i;
	for(i=0;i<N;i++)
	{
		scanf("%d", &num);
		ch[num]++;
	}

	for(i=0;i<10001;i++)
	{
		while(ch[i]--)
			printf("%d\n", i);
	}
}
