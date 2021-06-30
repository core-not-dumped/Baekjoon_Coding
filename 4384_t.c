#include <stdio.h>
#include <memory.h>

int main(void)
{
	int N;
	scanf("%d", &N);
	
	int w[101];
	int i, j, sum = 0;
	long long K[45452];
	memset(K, 0, sizeof(K));
	for(i=0;i<N;i++)
	{
		scanf("%d", &w[i]);
		sum += w[i];
	}

	K[0] = 1;
	K[w[0]] = 2;

	for(i=2;i<N;i++)
	{
		for(j=sum;j>=0;j--)
		{
			if(K[j])
				K[j+w[i]] |= (K[j] << 1);
		}
	}

	long long ch = ((long long)1 << N/2);
	int ans;
	for(i=sum/2,j=sum/2;j>=0;i++,j--)
	{
		if(ch & K[i])	{	ans = i;	break;	}
		if(ch & K[j])	{	ans = j;	break;	}
	}

	int min = (ans < (sum-ans)) ? ans : (sum-ans);
	printf("%d %d\n", min, sum-min);

	return 0;
}
