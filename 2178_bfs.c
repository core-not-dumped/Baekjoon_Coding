#include <stdio.h>

int main(void)
{
	int N, M;
	scanf("%d %d", &N, &M);

	int i, j;
	int map[110][110];
	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
			scanf("%1d", &map[i][j]);
	}

	int ch[110][110];
	int qH[10002], qV[10002];
	int H, V;
	int f = 0;
	int r = 0;
	int l;

	int pH[4] = {-1,1,0,0};
	int pV[4] = {0,0,1,-1};

	qH[0] = 0;
	qV[0] = 0;
	ch[0][0] = 1;
	while(r <= f)
	{
		H = qH[r];
		V = qV[r];
		l = ch[H][V];
		for(i=0;i<4;i++)
		{
			if((H+pH[i] < 0) || (H+pH[i] > N-1))	continue;
			if((V+pV[i] < 0) || (V+pV[i] > M-1))	continue;

			if(map[H+pH[i]][V+pV[i]] == 1 && ch[H+pH[i]][V+pV[i]] == 0)
			{
				ch[H+pH[i]][V+pV[i]] = l+1;
				f++;
				qH[f] = H+pH[i];
				qV[f] = V+pV[i];
			}
		}
		r++;
	}

	printf("%d\n", ch[N-1][M-1]);

	return 0;
}
