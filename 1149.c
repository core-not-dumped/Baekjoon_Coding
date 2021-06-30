#include <stdio.h>
#include <memory.h>

int main(void)
{
	int Rdp[1001], Gdp[1001], Bdp[1001];
	memset(Rdp,0,sizeof(Rdp));
	memset(Gdp,0,sizeof(Gdp));
	memset(Bdp,0,sizeof(Bdp));

	int N;
	scanf("%d", &N);
	
	int R, G, B;
	for(int i=0;i<N;i++)
	{
		scanf("%d %d %d", &R, &G, &B);
		Rdp[i+1] = (Gdp[i] + R > Bdp[i] + R) ? Bdp[i] + R : Gdp[i] + R;
		Gdp[i+1] = (Rdp[i] + G > Bdp[i] + G) ? Bdp[i] + G : Rdp[i] + G;
		Bdp[i+1] = (Rdp[i] + B > Gdp[i] + B) ? Gdp[i] + B : Rdp[i] + B;
	}

	if(Rdp[N] < Gdp[N] && Rdp[N] < Bdp[N])	printf("%d\n", Rdp[N]);
	else if(Gdp[N] < Bdp[N])				printf("%d\n", Gdp[N]);
	else									printf("%d\n", Bdp[N]);

	return 0;
}
