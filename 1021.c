#include <stdio.h>

#define MAX 10000

int main(void)
{
	int N, M;
	scanf("%d %d", &N, &M);

	int a[50];
	int i;
	for(i=0;i<M;i++)
		scanf("%d", &a[i]);

	int ans = 0;
	int q[2][MAX];
	int r[2] = {MAX/2-1, MAX/2-1};
	int f[2] = {MAX/2+N, MAX/2+N};
	for(i=MAX/2;i<MAX/2+N;i++)
	{
		q[0][i] = i-MAX/2+1;
		q[1][i] = i-MAX/2+1;
	}

	int j;
	for(i=0;i<M;i++)
	{
		int ch = 0;
		while(1)
		{
			if(q[0][r[0]+1] == a[i])	{ ch = 0;	break; }
			if(q[1][r[1]+1] == a[i])	{ ch = 1;	break; }
			q[0][f[0]++] = q[0][++r[0]];
			q[1][r[1]--] = q[1][--f[1]];
			ans++;
		}

		r[ch]++;
		for(j=r[ch]+1;j<f[ch];j++)
			q[!ch][j] = q[ch][j];

		r[!ch] = r[ch];
		f[!ch] = f[ch];
	}

	printf("%d\n", ans);

	return 0;
}
