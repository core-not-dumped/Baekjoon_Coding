#include <stdio.h>
#include <string.h>

int main(void)
{
	char s1[1002];
	char s2[1002];
	
	scanf("%s", s1);
	scanf("%s", s2);

	int len1 = strlen(s1);
	int len2 = strlen(s2);

	int dp[1001][1001];
	int i, j;
	int max;
	for(i=1;i<len1+1;i++)
	{
		for(j=1;j<len2+1;j++)
		{
			if(s1[i-1] == s2[j-1])
				max = dp[i-1][j-1]+1;
			else
				max = dp[i-1][j] > dp[i][j-1] ? dp[i-1][j] : dp[i][j-1];
			dp[i][j] = max;
		}
	}

	printf("%d\n", dp[len1][len2]);

	return 0;
}
