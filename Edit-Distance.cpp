https://leetcode.com/problems/edit-distance/

class Solution {
public:
    int minDistance(string s1, string s2) {
        
    int m=s1.length();
	int n= s2.length();
	int **dp = new int*[m+1];

	for(int i=0;i<=m;i++) dp[i]= new int[n+1];

	int len2= n;
	
	for(int j=0;j<=n;j++)
	{
		dp[m][j]= len2;
		len2--;
	}

	int len1= m;
	for(int i=0;i<=m;i++)
	{
		dp[i][n]= len1;
		len1--;
	}

	for(int i=m-1;i>=0;i--)
	{
		for(int j=n-1;j>=0;j--)
		{
			if(s1[i]==s2[j])
			{
				dp[i][j]= min(1+dp[i+1][j],min(1+dp[i][j+1],dp[i+1][j+1]));

			}
			else dp[i][j]=min(dp[i+1][j],min(dp[i][j+1],dp[i+1][j+1]))+1;

		}
	}

	return dp[0][0];
        
    }
};
