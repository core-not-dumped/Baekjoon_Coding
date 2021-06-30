#include <stdio.h>
#include <memory.h>

int main(void)
{
	int A, B, C;
	int mul;
	scanf("%d %d %d", &A, &B, &C);

	mul = A*B*C;

	int i;
	int num[11], r;
	memset(num, 0, sizeof(num));
	while(mul)
	{
		r = mul%10;
		num[r]++;
		mul /= 10;
	}

	for(i=0;i<10;i++)
		printf("%d\n", num[i]);

	return 0;
}
