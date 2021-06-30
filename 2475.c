#include <stdio.h>

int main(void)
{
	int i;
	int ans = 0;
	int num;
	for(i=0;i<5;i++)
	{
		scanf("%d", &num);
		ans += num * num;
	}
	
	printf("%d\n", ans%10);
	
	return 0;
}
