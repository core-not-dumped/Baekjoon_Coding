#include <stdio.h>

int max, min;
int num[12], op[5];
int N;

int operate(int o, int num1, int num2)
{
	if(o == 0)	return num1+num2;
	else if(o == 1)	return num1-num2;
	else if(o == 2)	return num1*num2;
	else	return num1/num2;
}

void back(int n, int cal)
{
	if(N == n)
	{
		if(max < cal)	max = cal;
		if(min > cal)	min = cal;
		return;
	}

	int tmp = cal;
	int i;
	for(i=0;i<4;i++)
	{
		if(op[i] > 0)
		{
			op[i]--;
			cal = operate(i,cal,num[n]);

			back(n+1, cal);

			op[i]++;
			cal = tmp;
		}
	}
}

int main(void)
{
	max = -2100000000;
	min = 2100000000;

	scanf("%d", &N);

	int i;
	for(i=0;i<N;i++)
		scanf("%d", &num[i]);

	// +, -, *, /
	for(i=0;i<4;i++)
		scanf("%d", &op[i]);
	
	back(1, num[0]);

	printf("%d\n%d\n", max, min);

	return 0;
}
