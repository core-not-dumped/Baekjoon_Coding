#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

int N, M;
int currentH, currentV;
int map[21][21], pmap[21][21];
int fH[401], fV[401];
int person, fuel;

void BFS(int k)
{
	int i, j;
	int maptmp[21][21];
	for(i=0;i<N;i++)
	memset(maptmp[i],0,sizeof(int)*21);
	maptmp[currentH][currentV] = 1;

	int pH[4] = {1,0,-1,0};
	int pV[4] = {0,1,0,-1};
	int qH[401] = {currentH, };
	int qV[401] = {currentV, };
	int H, V, minH, minV, dis;
	int r = 0,f = 1;
	int min = 512;
	qH[0] = currentH;
	qV[0] = currentV;

	if(k && fH[person] == currentH && fV[person] == currentV)
		return;
	if(!k && pmap[currentH][currentV])
	{
		person = pmap[currentH][currentV];
		pmap[currentH][currentV] = 0;
		return;
	}

	while(r<f)
	{
		for(i=0;i<4;i++)
		{
			if(maptmp[qH[r]][qV[r]] >= min)	break;

			H = qH[r] + pH[i];
			V = qV[r] + pV[i];
			if(maptmp[H][V] || map[H][V])	continue;
			if(H < 0 || H >= N)	continue;
			if(V < 0 || V >= N)	continue;

			dis = maptmp[qH[r]][qV[r]] + 1;
			if(k)
			{
				if(fH[person] == H && fV[person] == V)
				{
					min = dis;
					minH = H;
					minV = V;
					r = 1000;
					break;
				}
			}
			else
			{
				if(pmap[H][V])
				{
					if(min > dis)
					{
						minH = H;
						minV = V;
						min = dis;
					}
					else if(min == dis)
					{
						if(minH > H)
						{
							minH = H;
							minV = V;
						}
						if(minH == H && minV > V)
						{
							minH = H;
							minV = V;
						}
					}
				}
			}

			maptmp[H][V] = dis;
			qH[f] = H;
			qV[f] = V;
			f++;
		}
		r++;
	}

	min--;

	if(fuel < min || min == 511 || (fuel == min && !k))
	{
		printf("-1\n");
		exit(0);
	}

	currentH = minH;
	currentV = minV;

	if(k)	fuel += min;
	else
	{
		person = pmap[minH][minV];
		pmap[minH][minV] = 0;
		fuel -= min;
	}
}

int main(void)
{
	scanf("%d %d %d", &N, &M, &fuel);

	int i, j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
			scanf("%d", &map[i][j]);
	}

	scanf("%d %d", &currentH, &currentV);
	currentH--;
	currentV--;

	int a1,b1,a2,b2;
	for(i=0;i<M;i++)
	{
		scanf("%d %d %d %d", &a1, &b1, &a2, &b2);
		pmap[a1-1][b1-1] = i+1;
		fH[i+1] = a2-1;
		fV[i+1] = b2-1;
	}

	for(i=0;i<M;i++)
	{
		BFS(0);
		BFS(1);
	}

	printf("%d\n", fuel);
	return 0;
}
