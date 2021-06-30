#include <stdio.h>

int main(void)
{
	int K;
	scanf("%d", &K);

	int stack[100000];
	int sp = 0;
	int num;
	int i;
	for(i=0;i<K;i++)
	{
		scanf("%d", &num);
		if(num == 0)	sp--;
		else	stack[sp++] = num;
	}

	int sum = 0;
	for(i=0;i<sp;i++)
		sum += stack[i];

	printf("%d\n", sum);

	return 0;
}
