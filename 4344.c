#include <stdio.h>
#include <memory.h>

int main(void)
{
	int C, t;
	scanf("%d", &C);
	for(t=0;t<C;t++)
	{
		int N, i;
		scanf("%d", &N);
		
		int score[1001], sum=0;
		memset(score,0,sizeof(score));
		for(i=0;i<N;i++)
		{
			scanf("%d", &score[i]);
			sum += score[i];
		}
		
		float average = sum/N;
		int num = 0;
		for(i=0;i<N;i++)
		{
			if(average < score[i])	num++;
		}

		float ans = ((float)num)/((float)N);
		printf("%.3f%\n", (float)100*ans);
	}

	return 0;

}
