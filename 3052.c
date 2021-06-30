#include <stdio.h>
#include <memory.h>

int main(void)
{
	int i, a;
	int res[43];
	memset(res, 0, sizeof(res));
	for(i=0;i<10;i++)
	{
		scanf("%d", &a);
		res[a%42]++;
	}

	int another = 0;
	for(i=0;i<42;i++)
	{
		if(res[i])	another++;
	}

	printf("%d\n", another);

	return 0;
}
