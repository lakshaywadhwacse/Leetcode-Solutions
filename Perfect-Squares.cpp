https://leetcode.com/problems/perfect-squares/

class Solution {
public:
    int numSquares(int n) {
        
    int *dp = new int[n+1];
	for(int i=0;i<=n;i++) dp[i]=-1;

	dp[0]=0;

	for(int i=1;i<=n;i++)
	{
		int minin=INT_MAX;
		for(int j=1;j*j<=i;j++)
		{
			int ans= dp[i-j*j];
			minin= min(minin,ans);
		}
		dp[i]=1+minin;
	}
        
    return dp[n];
        
    }
};
