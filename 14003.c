#include <stdio.h>

#define MAX 100000001

typedef struct dp{
	int num, index;
}DP;

DP d[100001];

int main(void)
{
	int N;
	scanf("%d", &N);

	int i;
	int ans = 0;
	int val[100001];
	int before[100001];
	d[0] = (DP) {MAX, -1};
	for(i=0;i<N;i++)
	{
		int num;
		scanf("%d", &num);

		val[i] = num;
		if(d[ans].num < num)
		{
			before[i] = d[ans++].index;
			d[ans].num = num;
			d[ans].index = i;
		}
		else
		{
			int ind;
			int left = 0, right = ans;
			while(left <= right)
			{
				int h = (left + right) / 2;
				if(d[h].num >= num)
				{
					right = h-1;
					ind = h;
				}
				else	left = h+1;
			}
			if(!ind)	before[i] = -1;
			else		before[i] = d[ind-1].index;

			d[ind].num = num;
			d[ind].index = i;
		}
	}

	printf("%d\n", ans+1);

	int anstmp = ans;
	int ansarr[100001];
	int bigind = d[ans].index;
	ansarr[ans] = val[bigind];
	while(before[bigind] != -1)
	{
		ansarr[--ans] = val[before[bigind]];
		bigind = before[bigind];
	}

	for(i=0;i<=anstmp;i++)
		printf("%d ", ansarr[i]);
	printf("\n");

	return 0;
}
