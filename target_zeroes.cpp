#include<bits/stdc++.h>
using namespace std;

vector<int> targetzeros(int n)
{
	int n1 = floor(n/2.0);
	vector<int>v;
	for(int i=1;i<=n1;i++)
	{
		v.push_back(i);
		v.push_back(-1*i);
	}

	if(n%2!=0)
	{
		v.push_back(0);
	}

	return v;

}

int main()
{
	int n;
	cin>>n;
	vector<int> ans=targetzeros(n);
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;

}