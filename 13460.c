#include <stdio.h>
#include <stdlib.h>

int N, M;
char map[11][11];
int px[4] = {1,0,-1,0};
int py[4] = {0,1,0,-1};
int R[2], Rtmp[2];
int B[2], Btmp[2];
int ans;
int maptmp[11][11];

int right_d(int direction)
{
	int i, j;
	int collision = 0;
	int ch = 0;
	for(i=1;;i++)
	{
		int x = Btmp[0] + px[direction] * i;
		int y = Btmp[1] + py[direction] * i;
		if(maptmp[x][y] == '.')	continue;
		else if(maptmp[x][y] == 'R' && !collision)
		{
			collision = 1;
			for(j=1;;j++)
			{
				int xtmp = Rtmp[0] + px[direction] * j;
				int ytmp = Rtmp[1] + py[direction] * j;
				if(maptmp[xtmp][ytmp] == '.')	continue;
				else if(maptmp[xtmp][ytmp] == 'O')	ch = 1;
				else	break;
			}
			if(ch)
				maptmp[Rtmp[0]][Rtmp[1]] = '.';
			else
			{
				maptmp[Rtmp[0]][Rtmp[1]] = '.';
				Rtmp[0] = Rtmp[0] + px[direction] * (j-1);
				Rtmp[1] = Rtmp[1] + py[direction] * (j-1);
				maptmp[Rtmp[0]][Rtmp[1]] = 'R';
			}
			i--;
		}
		else if(maptmp[x][y] == 'O')	return 1;
		else	break;
	}
	if(ch)	return 2;
	maptmp[Btmp[0]][Btmp[1]] = '.';
	Btmp[0] = Btmp[0] + px[direction] * (i-1);
	Btmp[1] = Btmp[1] + py[direction] * (i-1);
	maptmp[Btmp[0]][Btmp[1]] = 'B';

	for(i=1;;i++)
	{
		int x = Rtmp[0] + px[direction] * i;
		int y = Rtmp[1] + py[direction] * i;
		if(maptmp[x][y] == '.')			continue;
		else if(maptmp[x][y] == 'O')	return 2;
		else							break;
	}
	maptmp[Rtmp[0]][Rtmp[1]] = '.';
	Rtmp[0] = Rtmp[0] + px[direction] * (i-1);
	Rtmp[1] = Rtmp[1] + py[direction] * (i-1);
	maptmp[Rtmp[0]][Rtmp[1]] = 'R';

	return 0;
}

void dfs(int n, int before_d)
{
	int i, j, k;

	if(n >= 10)	return;

	for(i=0;i<4;i++)
	{
		int maptmp2[11][11];
		int Btmp2[2] = {B[0], B[1]};
		int Rtmp2[2] = {R[0], R[1]};
		for(j=0;j<N;j++)
		{
			for(k=0;k<M;k++)
			maptmp2[j][k] = map[j][k];
		}
		for(j=0;j<N;j++)
		{
			for(k=0;k<M;k++)
			maptmp[j][k] = map[j][k];
		}
		Rtmp[0] = R[0];	Rtmp[1] = R[1];
		Btmp[0] = B[0];	Btmp[1] = B[1];

		if(i != before_d)
		{
			int tmp = right_d(i);
			if(tmp == 1)	continue;
			else if(tmp == 2)
			{
				if(ans > n)	ans = n;
				continue;
			}

			for(j=0;j<N;j++)
			{
				for(k=0;k<M;k++)
				map[j][k] = maptmp[j][k];
			}
			R[0] = Rtmp[0];	R[1] = Rtmp[1];
			B[0] = Btmp[0];	B[1] = Btmp[1];

			dfs(n+1, i);

			for(j=0;j<N;j++)
			{
				for(k=0;k<M;k++)
				map[j][k] = maptmp2[j][k];
			}
			R[0] = Rtmp2[0];	R[1] = Rtmp2[1];
			B[0] = Btmp2[0];	B[1] = Btmp2[1];
		}
	}
}

int main(void)
{
	scanf("%d %d", &N, &M);

	int i, j;
	for(i=0;i<N;i++)
	scanf("%s", map[i]);

	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
		{
			if(map[i][j] == 'R')
			{
				R[0] = i;
				R[1] = j;
			}
			if(map[i][j] == 'B')
			{
				B[0] = i;
				B[1] = j;
			}
		}
	}

	ans = 100;

	dfs(0, -1);

	if(ans == 100)	printf("-1\n");
	else			printf("%d\n", ans+1);

	return 0;
}
