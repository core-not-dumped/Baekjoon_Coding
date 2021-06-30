#include <stdio.h>
#include <memory.h>

int check(int a, int i)
{
	if(i == 0)	return a+1;
	if(i == 1)	return a-1;
	if(i == 2)	return a*2;
}

int main(void)
{
	int M, N;
	scanf("%d %d", &M, &N);

	if(M==N)
	{
		printf("0\n");
		return 0;
	}

	int i;
	int m;
	int line[100001];
	int q[100001];
	int r, f;
	memset(line,0,sizeof(line));
	memset(q,0,sizeof(q));
	q[0] = M;
	line[M] = 1;
	r = 0;
	f = 1;

	while(r<f)
	{
		for(i=0;i<3;i++)
		{
			m = check(q[r],i);
			if(m < 0 || m > 100000)	continue;

			if(m ==	N)
			{
				printf("%d\n", line[q[r]]);
				return 0;
			}
			if(line[m] == 0)
			{
				line[m] = line[q[r]]+1;
				q[f] = m;
				f++;
			}
		}
		r++;
	}

	return 0;
}
