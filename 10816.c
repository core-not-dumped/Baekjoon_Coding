#include <stdio.h>
#include <stdlib.h>

int comp(const void *A, const void *B)
{
	if(*(int *)A < *(int *)B)	return -1;
	if(*(int *)A > *(int *)B)	return 1;
	else	return 0;
}

int main(void)
{
	int N;
	scanf("%d", &N);
	
	int i, j;
	int card[500000];
	for(i=0;i<N;i++)
		scanf("%d", &card[i]);
		
	qsort(card, N, sizeof(int), comp);		
		
	int M;
	scanf("%d", &M);
	
	int ch = 0;
	int cardnum[500000];
	for(i=0;i<N;i++)
	{
		int num = 1;
		for(j=i+1;j<N;j++)
		{
			if(card[i] == card[j])	num++;
			else	break;
		}
		card[ch] = card[i];
		cardnum[ch++] = num;
		i = j-1;
	}
	N = ch;
	
	for(i=0;i<M;i++)
	{
		int num;
		scanf("%d", &num);
		
		int *tmp;
		tmp = bsearch(&num,card,N,sizeof(int),comp);
		
		if(tmp == NULL)	printf("0 ");
		else	printf("%d ", cardnum[tmp-card]);
	}
	printf("\n");
	
	return 0;
}
