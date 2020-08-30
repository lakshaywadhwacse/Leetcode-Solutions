
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n, ans=0, maxh=INT_MIN;
		cin>>n;

		for(int i=0;i<n;i++)
		{
			int num;
			cin>>num;
			if(num>=maxh)
			{
				ans++;
				maxh=num;
			}
		}

		cout<<ans<<endl;



	}

	return 0;
}