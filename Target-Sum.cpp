https://leetcode.com/problems/target-sum/

class Solution {
public:
    int s1(vector<int>nums)
{
	int ans=0;
	for(int i=0;i<nums.size();i++)
	{
		ans=ans-nums[i];
	}
	return ans;
}

int s2(vector<int>nums)
{
	int ans=0;
	for(int i=0;i<nums.size();i++)
	{
		ans=ans+nums[i];
	}

	return ans;
}

int findTargetSumWays(vector<int>&nums, int S)
{
	int minsum=s1(nums);
	int maxsum = s2(nums);

	if(S>maxsum || S<minsum) return 0;

	int r= nums.size();
	int c= maxsum-minsum+1;

	int **dp= new int*[r];

	for(int i=0;i<r;i++)
	{
		dp[i]=new int[c];
	}

	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			dp[i][j]=0;
		}
	}

	// Initialize the first Row

	for(int i=0;i<c;i++)
	{
		bool op1= (i+minsum) == nums[0];
		bool op2= (i+minsum)== (-1)*nums[0];

		if(op1)
			dp[0][i]+=1;
		if(op2)
			dp[0][i]+=1;
	}

	// Build the rest of matrix

	for(int i=1;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			int a1= (j-nums[i]>=0)? dp[i-1][j-nums[i]]:0;
			int a2= (j+nums[i]<c)? dp[i-1][j+nums[i]]:0;
			dp[i][j]=a1+a2;
		}
	}

	return dp[r-1][S-minsum];
}
};
