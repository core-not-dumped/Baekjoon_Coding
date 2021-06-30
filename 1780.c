#include <stdio.h>

int N, map[2200][2200];
int z, o, m; 

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
	if(map[sx][sy] == 1)	{ o++; return; }
	else if(!map[sx][sy])	{ z++; return; }
	else					{ m++; return; }
	
	next:
	{
		int tx = (ex-sx)/3;
		int ty = (ey-sy)/3;
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				int nx = sx + tx * i;
				int ny = sy + ty * j;
				cut(nx,nx+tx,ny,ny+ty);
			}
		}
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
	
	m = z = o = 0;
	cut(0,N,0,N);
	
	printf("%d\n%d\n%d\n", m, z, o);
	
	return 0;
}
