#include <stdio.h>

int main(void)
{
	int N;
	scanf("%d", &N);

	int i;
	int a[100];
	for(i=0;i<N;i++)
	scanf("%d", &a[i]);

	int num;
	scanf("%d", &num);

	// num보다 작은수중에서 가장 큰수를 구한다.
	// a[h] < num을 a[h] <= num으로 바꾸어주면
	// num보다 같거나 작은수중에서 가장 큰수를 구한다.
	int left = 0, right = N-1;
	int ansindex;
	while(left <= right)
	{
		int h = (left + right) / 2;
		if(a[h] < num)
		{
			left = h+1;
			ansindex = h;
		}
		else			right = h-1;
	}

	printf("%d\n", a[ansindex]);


	// 위와 비슷하게 num보다 큰 수 중에서 가장작은수를 구한다.
	left = 0, right = N-1;
	while(left <= right)
	{
		int h = (left + right) / 2;
		if(a[h] > num)
		{
			right = h-1;
			ansindex = h;
		}
		else			left = h+1;
	}

	printf("%d\n", a[ansindex]);

	return 0;
}
