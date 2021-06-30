#include <stdio.h>

int main(void)
{
	int N;
	scanf("%d", &N);
	
	int sum = 0;
	sum += N/5;
	sum += N/25;
	sum += N/125;
	
	printf("%d\n", sum);
}
