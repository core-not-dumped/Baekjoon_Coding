#include <stdio.h>

int N;
int map[100][100];

void cut(int xs, int xe, int ys, int ye)
{
	int i, j;
	for(i=xs;i<xe;i++)
	{
		for(j=ys;j<ye;j++)
		{
			if(map[xs][ys] != map[i][j])
				goto next;
		}
	}
	if(map[xs][ys])	{ printf("1");	return; }
	else			{ printf("0");	return; }
	
	next:
	{
		int xh = (xs + xe) / 2;
		int yh = (ys + ye) / 2;
		printf("(");
		cut(xs,xh,ys,yh);
		cut(xs,xh,yh,ye);
		cut(xh,xe,ys,yh);
		cut(xh,xe,yh,ye);
		printf(")");
	}
}

int main(void)
{
	scanf("%d", &N);
	
	int i, j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
			scanf("%1d", &map[i][j]);
	}
	
	cut(0,N,0,N);
	
	return 0;
}
