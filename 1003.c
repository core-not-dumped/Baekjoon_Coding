#include <stdio.h>
#include <memory.h>

int main (void)
{
	int i;
	int func0[50], func1[50];
	memset(func0,0,sizeof(func0));
	memset(func1,0,sizeof(func1));
	func0[0] = 1;
	func1[1] = 1;
	for(i=0;i<40;i++)
	{
		func0[i+2] = func0[i+1] + func0[i];
		func1[i+2] = func1[i+1] + func1[i];
	}


	int T, t;
	int N;
	scanf("%d", &T);
	for(t=0;t<T;t++)
	{
		scanf("%d", &N);
		printf("%d %d\n", func0[N], func1[N]);
	}

	return 0;
}
