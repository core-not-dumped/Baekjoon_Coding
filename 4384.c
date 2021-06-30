#include <stdio.h>

int main(void)
{
	int N, K[101];
	scanf("%d", &N);

	int i, j, k;
	int sum = 0;
	for(i=0;i<N;i++)
	{
		scanf("%d", &K[i]);
		sum += K[i];
	}

	_Bool w[52][22501];
	int s;
	int b;
	w[0][0] = 1;
	for(i=0;i<N;i++)
	{
		s = (i > N/2) ? N/2 : i;

		for(k=s;k>0;k--)
		{
			b = ((450*i) < (sum/2)) ? (450*i) : (sum/2);
			for(j=0;j<=b;j++)
			{
				if(w[k][j] == 1)
				{
					if((j + K[i]) < (sum/2+1))
						w[k+1][j + K[i]] = 1;
				}
			}
		}
		w[1][K[i]] = 1;
	}

	if(N%2 == 1)
	{
		for(i=sum/2;i>0;i--)
		{
			if(w[N/2][i] == 1)	break;
			if(w[N/2+1][i] == 1)	break;
		}
	}
	else
	{
		for(i=sum/2;i>0;i--)
		{
			if(w[N/2][i] == 1)	break;
		}
	}

	int min = (i > (sum - i)) ? (sum-i) : i;
	printf("%d %d\n", min, sum-min);

	return 0;
}
