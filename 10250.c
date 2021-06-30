#include <stdio.h>

int main(void)
{
	int T, t;
	scanf("%d", &T);
	for(t=0;t<T;t++)
	{
		int H, W, N;
		scanf("%d %d %d", &H, &W, &N);
		if(!(N%H))
			printf("%d%02d\n", H, N/H);
		else
			printf("%d%02d\n", N%H, (N/H)+1);
	}

	return 0;
}
