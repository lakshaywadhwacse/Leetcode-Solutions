int longestCommonSubsequence(string text1, string text2)
{

	int n= text1.length();
	int m= text2.length();

	int **dp = new int*[n+1];

	for(int i=0;i<=n;i++)
	{
		dp[i]= new int[m+1];
	}

	for(int i=0;i<=m;i++)
	{
		dp[0][i]=0;
	}

	for(int i=0;i<=n;i++)
	{
		dp[i][0]=0;
	}

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(text1[i-1]==text2[j-1])
			{
				dp[i][j]=dp[i-1][j-1]+1;
			}
			else
			{
				dp[i][j]= max(dp[i][j-1],dp[i-1][j]);
			}
		}
	}

	return dp[n][m];
}