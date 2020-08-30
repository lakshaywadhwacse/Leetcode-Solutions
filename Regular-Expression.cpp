https://leetcode.com/problems/regular-expression-matching/submissions/

class Solution {
public:
    bool isMatch(string s, string p) {
    bool dp[1001][1001]={0};
	dp[0][0]=1;
	int n=s.length();
	int m=p.length();

	// Initialize the 0th row
	for(int j=1;j<=m;j++)
	{
		if(p[j-1]=='*')
		{
			dp[0][j]=dp[0][j-2];
		}
	}

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(p[j-1]==s[i-1] || p[j-1]=='.')
			{
				dp[i][j]=dp[i-1][j-1];
			}
			else if(p[j-1]=='*')
			{
				dp[i][j]=dp[i][j-2];
				if(p[j-2]==s[i-1]|| p[j-2]=='.')
				{
					dp[i][j]=(dp[i-1][j] || dp[i][j]);
				}
			}
			else
			{
				dp[i][j]=0;
			}
		}
	}

	return dp[n][m];
    }
};
