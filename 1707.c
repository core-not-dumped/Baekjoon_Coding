#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

struct line{
	int x, y;
}l[400000];

int comp(const void *A, const void *B)
{
	struct line *pA = (struct line *)A;
	struct line *pB = (struct line *)B;

	if(pA->x < pB->x)	return -1;
	if(pA->x > pB->x)	return 1;
	if(pA->y < pB->y)	return -1;
	else	return 1;
}

int main(void)
{
	int t;
	scanf("%d", &t);

	while(t--)
	{
		int V, E;
		scanf("%d %d", &V, &E);

		int i, j;
		for(i=0;i<E;i++)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			l[2*i] = (struct line){x, y};
			l[2*i+1] = (struct line){y, x};
		}

		qsort(l,2*E,sizeof(struct line), comp);

		int s[20001], e[20001];
		memset(s,-1,sizeof(s));
		memset(e,-1,sizeof(e));
		s[l[0].x] = 0;
		for(i=1;i<2*E;i++)
		{
			if(l[i-1].x != l[i].x)
			{
				e[l[i-1].x] = i-1;
				s[l[i].x] = i;
			}
		}
		e[l[2*E-1].x] = 2*E-1;
	
		int c[20001] = {0};
		for(i=1;i<=V;i++)
		{
			if(c[i])	continue;

			c[i] = 1;
			int q[20000] = {i,};
			int r = 0, f = 1;
			while(r < f)
			{
				for(j=s[q[r]];j<=e[q[r]];j++)
				{
					if(j == -1)	break;
					int ny = l[j].y;
					if(!c[ny])
					{
						q[f++] = ny;
						if(c[q[r]] == 1)	c[ny] = 2;
						if(c[q[r]] == 2)	c[ny] = 1;
					}
					else
					{
						if(c[q[r]] == c[ny])
						{
							printf("NO\n");
							goto next;
						}
					}
				}
				r++;
			}
		}
		printf("YES\n");
		next:
			continue;
	}

	return 0;
}
