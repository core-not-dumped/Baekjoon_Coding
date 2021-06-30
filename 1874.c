#include <stdio.h>

int main(void)
{
	int n;
	scanf("%d", &n);
	
	int i, arr[100000];
	for(i=0;i<n;i++)
		scanf("%d", &arr[i]);
	
	int stack[100000] = {1,};
	char pm[200001] = {'+',};
	int stp = 1, arrp = 0, pmp = 1;
	i = 2;
	while(1)
	{
		if(i <= arr[arrp])
		{
			stack[stp++] = i;
			pm[pmp++] = '+';
			i++;
		}
		else
		{
			while(arr[arrp] < i)
			{
				if(arrp == n)	break;
				if(stack[--stp] == arr[arrp++])
					pm[pmp++] = '-';
				else
				{
					printf("NO\n");
					return 0;
				}
			}
			if(i == n+1)	break;
		}
	}
	
	for(i=0;i<pmp;i++)
		printf("%c\n", pm[i]);
	
	return 0;
}
