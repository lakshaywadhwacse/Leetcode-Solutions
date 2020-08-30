//https://www.interviewbit.com/problems/palindromic-substrings-count/
//https://leetcode.com/problems/palindromic-substrings/submissions/
#include<iostream>
using namespace std;

int solve(string s)
{
	int n=s.length();
	bool dp[1001][1001]={0};

	for(int i=0;i<n;i++)
	{
		dp[i][i]=true;
	}

	for(int i=0;i<n-1;i++)
	{
		if(s[i]==s[i+1])
		{
			dp[i][i+1]=true;
		}
	}

	for(int d=2;d<n;d++)
	{
		int i=0;j=d;
		while(j<n)
		{
			if(s[i]==s[j] and dp[i+1][j-1])
			{
				dp[i][j]=true;
			}
			else
			{
				dp[i][j]=false;
			}
			i++;j++;
		}
	}

	int ans=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(dp[i][j]) ans++;
		}
	}

	return ans;
}