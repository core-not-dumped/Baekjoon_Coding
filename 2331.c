#include <stdio.h>

int cal(int a, int p)
{
	int ans = 0;
	int tmp;
	int i,j;
	for(i=0;i<6;i++)
	{
		if(a == 0)	break;

		tmp = 1;
		for(j=0;j<p;j++)
			tmp *= a%10;
		ans += tmp;
		a = a/10;
	}
	return ans;
}

int main(void)
{
	int A;
	int P;
	scanf("%d %d", &A, &P);
	
	int seq[10002];
	seq[0] = A;

	int a = A;
	int i, j;
	for(i=1;;i++)
	{
		a = cal(a, P);
		for(j=0;j<i;j++)
		{
			if(seq[j] == a)	break;
		}

		if(i == j)	seq[i] = a;
		else	break;
	}

	//수열 확인 코드
	/*int k;
	for(k=0;k<i;k++)
	{
		printf("%d ",seq[k]);
	}
	printf("\n");*/

	printf("%d\n", j);

	return 0;
}
