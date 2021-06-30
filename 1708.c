#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct v {
	long long x;
	long long y;
}ver[100000];

int CompareDoubleAbsoulte(double x, double y)
{
	double absTolerance = (1.0e-8);
    double diff = x - y;
    if (fabs(diff) <= absTolerance)
        return 0;

    return (diff > 0) ? 1 : -1;
}

int compare(const void *A, const void *B)
{
    struct v* ptrA = (struct v*)A;
    struct v* ptrB = (struct v*)B;

    if (ptrA->y < ptrB->y)	return -1;
	if (ptrA->y > ptrB->y)	return 1;
	if (ptrA->x < ptrB->x)	return -1;
	if (ptrA->x > ptrB->x)	return 1;
}

int comparecos(const void *A, const void *B)
{
    struct v* ptrA = (struct v*)A;
    struct v* ptrB = (struct v*)B;

	if((ptrA->x) * (ptrB->y) > (ptrA->y) * (ptrB->x))	return -1;
	if((ptrA->x) * (ptrB->y) < (ptrA->y) * (ptrB->x))	return 1;
	if (ptrA->y < ptrB->y)	return -1;
	if (ptrA->y > ptrB->y)	return 1;
}

int ccw(int f, int s, int n)
{
	long long vector1x = ver[s].x - ver[f].x;
	long long vector1y = ver[s].y - ver[f].y;
	long long vector2x = ver[n].x - ver[s].x;
	long long vector2y = ver[n].y - ver[s].y;

	printf("n: %d\n", n);
	printf("%lld %lld %lld %lld \n", vector1x, vector1y, vector2x, vector2y);
	printf("vector %lld\n", vector1x * vector2y - vector2x * vector1y);

	if((vector1x * vector2y - vector2x * vector1y) > 0)	return 1;
	else	return 0;
}

int main(void)
{
	int N;
	scanf("%d", &N);
	
	int i;
	for(i=0;i<N;i++)
		scanf("%lld %lld", &ver[i].x, &ver[i].y);

	// y 좌표가 가장 작은 것, y 값이 가장 작다면 x를 기준으로
	// 반시계 방향으로 스택에 넣는다.
	qsort(ver, N, sizeof(struct v), compare);

	/*for(i=0;i<N;i++)
		printf("x, y: %d %d\n", ver[i].x, ver[i].y);
	printf("\n");*/

	// 처음 좌표를 0으로 만들고, 나머지 좌표에서 처음 좌표를 빼준다
	// (처음 좌표를 (0,0)으로 이동시킨다.)
	// 위처럼 하면 (0,0)아래에 점은 존재하지 않는다.
	for(i=1;i<N;i++)
	{
		ver[i].x -= ver[0].x;
		ver[i].y -= ver[0].y;
	}
	ver[0].x = 0;
	ver[0].y = 0;

	// cos값을 구한후 큰 순서대로 배치한다.
	// cos값이 크면 클수록 x+축을 기준으로 반시계 방향으로 돌렸을때
	// 차례대로 array에 넣을 수 있다.
	qsort(&ver[1], N - 1, sizeof(struct v), comparecos);

	for(i=0;i<N;i++)
		printf("x, y: %lld %lld\n", ver[i].x, ver[i].y);
	printf("\n");

	int f, s, n;
	int stack[100000] = {0,1,};
	int stackpointer = 2;
	int j;
	for(i=2;i<N;i++)
	{
		printf("stack: ");
		for(j=0;j<stackpointer;j++)
		{
			printf("%d ", stack[j]);
		}
		printf("\n");
		n = i;
		int de = 0;
		for(j=0;j<N;j++)
		{
			if(stackpointer-j-2 < 0)	break;
			if(!ccw(stack[stackpointer-j-2], stack[stackpointer-j-1], n))	de++;
			else break;
		}
		stackpointer -= de;
		stack[stackpointer] = n;
		stackpointer++;
	}

	for(i=0;i<stackpointer;i++)
	printf("x, y: %lld %lld\n", ver[stack[i]].x, ver[stack[i]].y);

	printf("%d\n", stackpointer);

	return 0;
}
