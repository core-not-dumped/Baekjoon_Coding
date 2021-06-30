#include <stdio.h>

int main(void)
{
	int N;
	scanf("%d", &N);
	if(N == 1)	{	printf("1\n");	return 0;	}

	int q[1000000];
	int i;
	for(i=1;i<=N;i++)
		q[i-1] = i;

	int r = 0, f = N;
	while(r<f)
	{
		r++;
		if(r + 1 == f)	break;
		q[f++] = q[r++];
		if(r + 1 == f)	break;
	}

	printf("%d\n", q[f-1]);

	return 0;
}
