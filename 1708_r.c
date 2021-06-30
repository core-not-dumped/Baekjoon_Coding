#include <stdio.h>
#include <stdlib.h>

struct v {
	long long x;
	long long y;
}ver[100000];

int comp(const void *A, const void *B)
{
    struct v* pA = (struct v*)A;
    struct v* pB = (struct v*)B;

    if (pA->y < pB->y)	return -1;
	if (pA->y > pB->y)	return 1;
	if (pA->x < pB->x)	return -1;
	if (pA->x > pB->x)	return 1;
}

int compsin(const void *A, const void *B)
{
    struct v* pA = (struct v*)A;
    struct v* pB = (struct v*)B;

	if ((pA->x) * (pB->y) > (pA->y) * (pB->x))	return -1;
	if ((pA->x) * (pB->y) < (pA->y) * (pB->x))	return 1;
	if (pA->y < pB->y)	return -1;
	if (pA->y > pB->y)	return 1;
	if (pA->x < pB->x)	return -1;
	if (pA->x > pB->x)	return 1;
}

int ccw(int f, int s, int n)
{
	long long v1x = ver[s].x - ver[f].x;
	long long v1y = ver[s].y - ver[f].y;
	long long v2x = ver[n].x - ver[s].x;
	long long v2y = ver[n].y - ver[s].y;

	if((v1x * v2y - v2x * v1y) > 0)	return 1;
	else	return 0;
}

int main(void)
{
	int N;
	scanf("%d", &N);
	
	int i, j;
	for(i=0;i<N;i++)
		scanf("%lld %lld", &ver[i].x, &ver[i].y);

	qsort(ver, N, sizeof(struct v), comp);

	for(i=1;i<N;i++)
	{
		ver[i].x -= ver[0].x;
		ver[i].y -= ver[0].y;
	}
	ver[0].x = 0;
	ver[0].y = 0;

	qsort(&ver[1], N - 1, sizeof(struct v), compsin);

	int stack[100000] = {0,1,};
	int sp = 2;
	for(i=2;i<N;i++)
	{
		int de = 0;
		for(j=0;j<N;j++)
		{
			if(sp-j-2 < 0)	break;
			if(!ccw(stack[sp-j-2], stack[sp-j-1], i))	de++;
			else break;
		}
		sp -= de;
		stack[sp++] = i;
	}

	printf("%d\n", sp);

	return 0;
}
