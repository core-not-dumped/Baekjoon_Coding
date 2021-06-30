
#include <stdio.h>

int main(void)
{
	int n;
	scanf("%d", &n);

	int i;
	for(i=0;i<n;i++)
		printf("%d\n", n-i);

	return 0;
}
