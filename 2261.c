#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>

int n;
typedef struct _point{
	int x, y;
}point;

point p[100000];
point part_p[100000];

int compx(const void *A, const void *B)
{
	point *pA = (point *)A;
	point *pB = (point *)B;
	
	if(pA->x < pB->x)	return -1;
	if(pA->x > pB->x)	return 1;
	if(pA->y < pB->y)	return -1;
	else	return 1;
}

int compy(const void *A, const void *B)
{
	point *pA = (point *)A;
	point *pB = (point *)B;
	
	if(pA->y < pB->y)	return -1;
	if(pA->y > pB->y)	return 1;
	if(pA->x < pB->x)	return -1;
	else	return 1;
}

int dis(int a, int b)
{
	int dx = p[a].x - p[b].x;
	int dy = p[a].y - p[b].y;
	return dx * dx + dy * dy;
}

int s_dis(int s, int e)
{
	// 점이 1~3개 있을때
	if(s == e)		return 0;
	if(s+1 == e)	return dis(s, e);
	if(s+2 == e)
	{
		int d1 = dis(s,s+1);
		int d2 = dis(s+1,e);
		return d1 < d2 ? d1 : d2;
	}
	
	int i, j;
	int h = (s + e)/2;

	// 왼쪽에서 작은 거리, 오른쪽에서 작은거리
	// 둘중 작은거리를 d에 채택
	int dl = s_dis(s, h);
	int dr = s_dis(h+1, e);
	int d = dl < dr ? dl : dr;
	
	int sqrtd = (int)sqrt((double)d)+1;
	int l, r;

	// 가운데로 부터 x값이 d이하로 떨어진 점들만 색출
	for(l=h;l>=s;l--)
	{
		if(p[l].x < p[h+1].x - sqrtd)	break;
	}
	for(r=h+1;r<=e;r++)
	{
		if(p[r].x > p[h].x + sqrtd)		break;
	}
	l++;
	r--;
	
	int size = r - l + 1;
	if(size <= 1)	return d;

	// 위에서 구한 점을 part_p로 옮긴다.
	memcpy(part_p, p + l, sizeof(point) * size);

	// y값을 기준으로 정렬
	qsort(part_p, size, sizeof(point), compy);

	// y도 마찬가지로 d이하로 떨어진 값들을 비교해준다.
	for(i=0;i<size-1;i++)
	{
		for(j=i+1;j<size;j++)
		{
			if(part_p[i].y+sqrtd < part_p[j].y)	break;
			int dx = part_p[i].x - part_p[j].x;
			int dy = part_p[i].y - part_p[j].y;
			int dtmp = dx * dx + dy * dy;
			
			if(dtmp < d)
			{
				d = dtmp;
				sqrtd = (int) sqrt((double)d) + 1;
			}
		}
	}
	return d;
}

int main(void)
{
	scanf("%d", &n);
	
	int i, j;
	for(i=0;i<n;i++)
		scanf("%d %d", &p[i].x, &p[i].y);

	// x가 작은 순으로 sort	
	qsort(p, n, sizeof(point), compx);

	// 같은 점은 제거해준다.
	int tmpn = 0;
	memcpy(part_p,p,sizeof(point)*n);
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(part_p[i].x == part_p[j].x && part_p[i].y == part_p[j].y)	continue;
			else	break;
		}
		memcpy(p+tmpn, part_p+i, sizeof(point));
		tmpn++;
		i = j - 1;
	}
	n = tmpn;

	// short distance 출력
	printf("%d\n", s_dis(0, n-1));
	
	return 0;
}
