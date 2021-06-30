#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
	if(*(int *)a > *(int *)b)
		return 1;
	else if(*(int *)a < *(int *)b)
		return -1;
	else
		return 0;
}

int main(void)
{
	int N;
	scanf("%d", &N);

	int i;
	int num[500001];
	int ch[8003];
	int sum = 0;
	memset(ch,0,sizeof(ch));
	for(i=0;i<N;i++)
	{
		scanf("%d", &num[i]);
		sum += num[i];
		ch[num[i]+4000]++;
	}

	printf("%0.f\n", (double)sum/N);

	qsort(num, N, sizeof(int), compare);

	printf("%d\n", num[N/2]);

	int lot = 0;
	int min = -1;
	int mo;
	for(i=0;i<8002;i++)
	{
		if(lot == ch[i])
		{
			if(!min)	mo = i-4000;
			min++;
		}
		else if(lot < ch[i])
		{
			mo = i-4000;
			lot = ch[i];
			min = 0;
		}
	}
	printf("%d\n", mo);

	printf("%d\n", num[N-1]-num[0]);

	return 0;
}
