#include <stdio.h>

int r, c;
int ans;

void div(int sx, int ex, int sy, int ey)
{
	if(sx+1 == ex)	return;
	int p = (ex-sx)*(ex-sx)/4;
	int hx = (sx + ex)/2;	
	int hy = (sy + ey)/2;
	if(hx > c && hy > r)
		div(sx, hx, sy, hy);
	else if(hx > c && hy <= r)
	{
		ans += 2*p;
		div(sx, hx, hy, ey);
	}
	else if(hx <= c && hy > r)
	{
		ans += p;
		div(hx, ex, sy, hy);
	}
	else
	{
		ans += 3*p;
		div(hx, ex, hy, ey);
	}
}

int main(void)
{
	int N;
	scanf("%d", &N);

	scanf("%d %d", &r, &c);

	ans = 0;
	div(0,(1<<N),0,(1<<N));

	printf("%d\n", ans);

	return 0;
}
