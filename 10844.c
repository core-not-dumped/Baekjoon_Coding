#include <stdio.h>
#include <memory.h>

int main(void)
{
	int N;
	scanf("%d", &N);

	int p = 1e9;
	int i;
	int last[11], lasttmp[11];
	for(i=1;i<10;i++)	last[i] = 1;
	last[0] = 0;

	for(;N>1;N--)
	{
		lasttmp[0] = last[1];
		lasttmp[9] = last[8];
		for(i=1;i<9;i++)
		{
			lasttmp[i] = last[i-1] + last[i+1];
			if(lasttmp[i] > p)
				lasttmp[i] -= p;
		}

		for(i=0;i<10;i++)	last[i] = lasttmp[i];
	}

	int sum = 0;
	for(i=0;i<10;i++)
	{
		sum += last[i];
		if(sum > p)	sum -= p;
	}

	printf("%d\n", sum);

	return 0;
}
