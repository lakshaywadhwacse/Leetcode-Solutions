#include<iostream>
using namespace std;

int ways(int n)
{
	if(n==1|| n==2)
	{
		return n;
	}

	int * dp= new int[n+1];
	dp[0]=0;
	dp[1]=1;
	dp[2]=2;
	for(int i=3;i<=n;i++)
	{
		dp[i]=dp[i-1]+dp[i-2];
	}

	return dp[n];
}