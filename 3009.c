#include <stdio.h>
#include <memory.h>

int main(void)
{
	int i;
	int a, b;
	int mapa[1001];
	int mapb[1001];
	memset(mapa,0,sizeof(mapa));
	memset(mapb,0,sizeof(mapb));

	for(i=0;i<3;i++)
	{
		scanf("%d %d", &a, &b);
		mapa[a]++;	mapb[b]++;
	}

	for(i=0;i<1001;i++)
	{
		if(mapa[i]%2)	{ printf("%d ", i);	break; }
	}
	for(i=0;i<1001;i++)
	{
		if(mapb[i]%2)	{ printf("%d", i);	break; }
	}
	printf("\n");

	return 0;
}
