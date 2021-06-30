#include <stdio.h>

int N, map[200][200];
int z, o; 

void cut(int sx, int ex, int sy, int ey)
{
	int i, j;
	for(i=sx;i<ex;i++)
	{
		for(j=sy;j<ey;j++)
		{
			if(map[sx][sy] != map[i][j])
				goto next;
		}
	}
	if(!map[sx][sy])	{ z++; return; }
	else				{ o++; return; }
	
	next:
	{
		int hx = (sx+ex)/2;
		int hy = (sy+ey)/2;
		cut(sx,hx,sy,hy);
		cut(sx,hx,hy,ey);
		cut(hx,ex,sy,hy);
		cut(hx,ex,hy,ey);
	}
}

int main(void)
{
	scanf("%d", &N);
	
	int i, j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
			scanf("%d", &map[i][j]);
	}
	
	z = o = 0;
	cut(0,N,0,N);
	
	printf("%d\n%d\n", z, o);
	
	return 0;
}
