#include <stdio.h>

int cw(int g, int c)
{
	int l;
	int j;
	if(c == 1)
	{
		l = g % 2;
		g >>= 1;
		g &= 0x7f;
		g |= (l << 7);
	}
	else
	{
		l = g & 0x80;
		g <<= 1;
		g &= 0xfe;
		g += l / 0x80;
	}

	return g;
}

int main(void)
{
	int i, j;
	int num, p;
	int gear[5] = {0,};
	for(i=0;i<4;i++)
	{
		p = 7;
		for(j=0;j<8;j++)
		{
			scanf("%1d", &num);
			gear[i] += (num << p);
			p--;
		}
	}

	int direc[2] = {1, -1};
	int b, l, gnum;
	int w[2];

	scanf("%d", &b);
	for(i=0;i<b;i++)
	{
		scanf("%d %d", &gnum, &w[0]);
		w[1] = (w[0]==1) ? -1 : 1;
		gnum--;

		int next, curr, curNS, nextNS;
		int right = 0, left = 0;
		for(j=1;j<4;j++)
		{
			curr = gnum + j - 1;
			next = gnum + j;
			if(next >= 4)	break;

			curNS = (gear[curr] & 0x20) / 0x20;
			nextNS = (gear[next] & 0x2) / 0x2;
			if(curNS != nextNS)	right++;
			else	break;
		}
		for(j=1;j<4;j++)
		{
			curr = gnum - j + 1;
			next = gnum - j;
			if(next < 0)	break;

			curNS = (gear[curr] & 0x2) / 0x2;
			nextNS = (gear[next] & 0x20) / 0x20;
			if(curNS != nextNS)	left++;
			else	break;
		}

		gear[gnum] = cw(gear[gnum], w[0]);
		for(j=1;j<=right;j++)
			gear[gnum+j] = cw(gear[gnum+j], w[j%2]);
		for(j=1;j<=left;j++)
			gear[gnum-j] = cw(gear[gnum-j], w[j%2]);
	}
	
	int score = 0;
	for(i=0;i<4;i++)
	{
		if(gear[i] & 0x80)	score += (1 << i);
	}
	printf("%d\n", score);

	return 0;
}
