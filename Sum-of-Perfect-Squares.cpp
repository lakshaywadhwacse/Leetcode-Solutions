#include<bits/stdc++.h>
using namespace std;

int func(int n)
{

	//recursive case
	int minin= INT_MAX;


	for(int i=1;i*i<=n;i++)
	{
		int ans= func(n-i*i);
		minin= min(minin,ans);
	}

	return 1 + minin;


}

int top_down(int n, int *dp)
{
	if(dp[n]==-1)
	{
		if(n==0)
		{
			dp[n]==0;
			return 0;
		}

		int minin= INT_MAX;
		for(int i=1;i*i<=n;i++)
		{
			int ans= top_down(n-i*i);
			minin= min(minin, ans);
		}

		dp[n]=1+minin;
		return 1+minin;
	}

	else return dp[n];
}

int bottom_up(int n)
{
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

}

int main()
{
	int n, cin>>n;
	cout<<func(n)<<endl;

	int *dp= new int[n+1];
	for(int i=0;i<=n;i++)dp[i]=-1;
	cout<<top_down(n)<<endl;

}