#include <stdio.h>
#include <memory.h>

int N,d;
int map[21][21];

void BFS(int sh, int sv, int eat, int shark)
{
	int qH[401], qV[401], mapch[21][21];
	int pH[5] = {0,1,0,-1};
	int pV[5] = {1,0,-1,0};
	int H,V,ansH,ansV,dtmp;
	int r = 0, f = 1;
	int i,j;
	for(i=0;i<N;i++)
	memset(mapch[i],0,sizeof(int)*N);
	memset(qH,0,sizeof(qH));
	memset(qV,0,sizeof(qV));
	mapch[sh][sv] = 1;
	qH[0] = sh;
	qV[0] = sv;

	int min = 410;
	while(r<f)
	{
		for(i=0;i<4;i++)
		{
			H = qH[r] + pH[i];
			V = qV[r] + pV[i];
			if(H < 0 || H >= N)	continue;
			if(V < 0 || V >= N)	continue;
			if(mapch[H][V])	continue;
			if(map[H][V] > shark)	continue;

			if(map[H][V] && map[H][V] < shark)
			{
				dtmp = mapch[qH[r]][qV[r]]+1;
				if(dtmp < min)
				{
					min = dtmp;
					ansH = H;
					ansV = V;
				}
				else if(dtmp == min)
				{
					if(ansH > H)
					{
						ansH = H;
						ansV = V;
					}
					else if(ansH == H)
					{
						if(ansV > V)
						{
							ansH = H;
							ansV = V;
						}
					}
				}
			}
			mapch[H][V] = mapch[qH[r]][qV[r]] + 1;
			qH[f] = H;
			qV[f] = V;
			f++;
		}
		r++;
	}

	if(min == 410)	return;

	d += min - 1;
	eat++;
	if(eat == shark)
		eat -= shark++;
	map[ansH][ansV] = 0;

	BFS(ansH,ansV,eat,shark);	
}

int main(void)
{
	scanf("%d", &N);

	int i, j;
	int sh, sv;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			scanf("%d", &map[i][j]);
			if(map[i][j] == 9)
			{
				map[i][j] = 0;
				sh = i;
				sv = j;
			}
		}
	}

	d = 0;
	BFS(sh, sv, 0, 2);

	printf("%d\n", d);

	return 0;
}
