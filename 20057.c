#include <stdio.h>

int N, map[500][500];
int sandtmp;

int tona(int w, int sand)
{
	if(w == 0)	return sand*2/100;
	if(w == 1)	return sand*10/100;
	if(w == 2)	return sand*7/100;
	if(w == 3)	return sand*1/100;
	if(w == 4)	return sand*5/100;
	if(w == 5)	return sand*10/100;
	if(w == 6)	return sand*7/100;
	if(w == 7)	return sand*1/100;
	if(w == 8)	return sand*2/100;
	else	return sandtmp;
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

	int move = 1;
	int direc = 0;
	int ch = 0;
	int pH[4] = {0,1,0,-1};
	int pV[4] = {-1,0,1,0};
	int sand, outsand = 0;
	int H = N/2, V = N/2;
	int aH, aV, t;

	int paH[4][10] = {{-2,-1,-1,-1,0,1,1,1,2,0},
					  {0,1,0,-1,2,1,0,-1,0,1},
					  {-2,-1,-1,-1,0,1,1,1,2,0},
					  {0,-1,0,1,-2,-1,0,1,0,-1}};

	int paV[4][10] = {{0,-1,0,1,-2,-1,0,1,0,-1},
					  {-2,-1,-1,-1,0,1,1,1,2,0},
					  {0,1,0,-1,2,1,0,-1,0,1},
					  {2,1,1,1,0,-1,-1,-1,-2,0}};

	while(H > 0 || V > 0)
	{
		for(i=0;i<move;i++)
		{
			H += pH[direc];
			V += pV[direc];
			
			sand = map[H][V];
			sandtmp = sand;
			map[H][V] = 0;
			for(j=0;j<10;j++)
			{
				aH = H + paH[direc][j];
				aV = V + paV[direc][j];
				t = tona(j, sand);

				if(aH >= N || aH < 0)			outsand += t;
				else if( aV >= N || aV < 0)		outsand += t;
				else						map[aH][aV] += t;

				if(j!=9)	sandtmp -= t;
			}
		}

		if(direc == 3)	direc = 0;
		else	direc++;
		
		ch++;
		if(ch == 2)
		{
			move++;
			ch = 0;
		}
	}

	printf("%d\n", outsand);

	return 0;
}
