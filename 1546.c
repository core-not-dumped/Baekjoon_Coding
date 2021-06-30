#include <stdio.h>

int main(void)
{
	int N;
	scanf("%d", &N);

	int i, max = 0;
	float score[1001];
	for(i=0;i<N;i++)
	{
		scanf("%f", &score[i]);
		if(max < score[i])	max = score[i];
	}

	float sum = 0;
	for(i=0;i<N;i++)
	{
		score[i] /= max;
		score[i] *= 100;
		sum += score[i];
	}

	printf("%f\n", sum/N);

	return 0;
}
