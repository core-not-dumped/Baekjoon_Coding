#include <stdio.h>

int max;
int v;
int vH[11], vV[11];
int N, M;
int map[10][10];

void BFS()
{
	int maptmp[10][10];
	int i,j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
			maptmp[i][j] = map[i][j];
	}

	int qH[101], qV[101];
	for(i=0;i<v;i++)
	{
		qH[i] = vH[i];
		qV[i] = vV[i];
	}

	int H,V;
	int r=0,f=v;
	int pH[5] = {1,0,-1,0};
	int pV[5] = {0,1,0,-1};
	while(r<f)
	{
		for(i=0;i<4;i++)
		{
			H = qH[r]+pH[i];
			V = qV[r]+pV[i];
			if(H >= N || H < 0)	continue;
			if(V >= M || V < 0)	continue;
			if(!maptmp[H][V])
			{
				maptmp[H][V] = 2;
				qH[f] = H;
				qV[f] = V;
				f++;
			}
		}
		r++;
	}


	int ans = 0;
	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
		{
			if(!maptmp[i][j])	ans++;
		}
	}

	if(max < ans)
		max = ans;
}

void DFS(int a, int b, int num)
{
	if(num == 3)	{ BFS();	return; }

	do{
		(b+1!=M) ? : (a+=1);
		b = (b+1)%M;
		if(a >= N)	return;
	} while(map[a][b]);
	
	map[a][b] = 1;
	DFS(a,b,num+1);
	map[a][b] = 0;
	DFS(a,b,num);
}

int main(void)
{
	scanf("%d %d", &N, &M);

	int i,j;
	v=0;
	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
		{
			scanf("%d", &map[i][j]);
			if(map[i][j]==2)
			{
				vH[v]=i;
				vV[v]=j;
				v++;
			}
		}
	}

	max = 0;
	DFS(0,-1,0);

	printf("%d\n", max);

	return 0;
}
