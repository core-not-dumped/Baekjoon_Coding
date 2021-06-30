#include <stdio.h>

int main(void)
{
	int N;
	scanf("%d", &N);

	int m[1000000] = {1000001,};
	int tmp, i, size = 0;
	for(i=0;i<N;i++)
	{
		scanf("%d", &tmp);
		if(m[size] < tmp)	m[++size] = tmp;
		else
		{
			int p;
			int left = 0, right = size;
			while(left <= right)
			{
				int h = (left+right)/2;
				if(m[h] < tmp)	left = h+1;
				else
				{
					p = h;
					right = h-1;
				}
			}
			m[p] = tmp;
		}
	}

	printf("%d\n", size+1);

	return 0;
}
