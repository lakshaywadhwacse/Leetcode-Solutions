#include<iostream>
using namespace std;

int n;
int *a;
int dp[1001][1001];

int solve(int left, int right)
{
	//Base case
	if(right-left<=1)
	{
		return 0;
	}

	if(dp[left][right]!=-1)
	{
		return dp[left][right];
	}

	int ans=0;
	for(int pivot=left+1;pivot<right;pivot++)
	{
		ans=max(ans,a[left]*a[pivot]*a[right]+solve(left,pivot)+solve(pivot,right));
	}
	return dp[left][right]=ans;
}

int main()
{
	int n;
	cin>>n;
	memset(dp,-1,sizeof dp);

	a= new int[n+2];
	a[0]=a[n+1]=1;

	for(int i=1;i<=n;i++)
		cin>>a[i];

	cout<<solve(0,n+1)<<endl;
	return 0;
}