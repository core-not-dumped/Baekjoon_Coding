#include <stdio.h>
#include <memory.h>

int cal(int n, int a)
{
	if(n==0)	return a*3;
	if(n==1)	return a*2;
	if(n==2)	return a+1;
}

int main(void)
{
	int N;
	scanf("%d", &N);
	if(N==1)	{	printf("0\n");	return 0;}

	int map[1000001];
	int q[1000001];
	memset(map,0,sizeof(map));
	memset(q,0,sizeof(q));
	q[0] = 1;

	int r=0;
	int f=1;
	int i, num;
	while(r<f)
	{
		for(i=0;i<3;i++)
		{
			num = cal(i,q[r]);
			if(num > 1000000)	continue;
			if(num == N)
			{
				printf("%d\n", map[q[r]] + 1);
				return 0;
			}
			if(!map[num])
			{
				map[num] = map[q[r]] + 1;
				q[f] = num;
				f++;
			}
		}
		r++;
	}

	return 0;
}
