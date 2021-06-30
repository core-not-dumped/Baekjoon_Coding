#include <stdio.h>

long long sum(int *a, int n)
{
	int i;
	long long s = 0;
	for(i=0;i<n;i++)
		s += a[i];
	return s;
}
