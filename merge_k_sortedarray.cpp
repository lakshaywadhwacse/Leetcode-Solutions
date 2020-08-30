#include<bits/stdc++.h>
using namespace std;
void mergeksortedarray(vector<vector<int>>karray)
{
	int k= karray.size();
	priority_queue<pair<int,pair<int,int>>,  vector<pair<int,pair<int,int>>>,  greater<pair<int,pair<int,int>>> >q;
	vector<int>output;
	for(int i=0;i<k;i++)
	{
		q.push(make_pair(karray[i][0],make_pair(i,0)));
	}
	int index=0;
	while(q.top().first!=INT_MAX)
	{
		output.push_back(q.top().first);
		int array_no= q.top().second.first;
		int array_index=q.top().second.second;

		if(array_index==karray[0].size()-1)
		{
			q.pop();
			q.push(make_pair(INT_MAX,make_pair(array_no,array_index+1)));
		}
		else
		{
			q.pop();
		    q.push(make_pair(karray[array_no][array_index+1],make_pair(array_no,array_index+1)));
		}
		index++;
	}

	for(int i=0;i<output.size();i++)
	{
		cout<<output[i]<<" ";
	}
	return;
}

int main()
{
	int t;
	cin>>t;
	vector<vector<int>>karray;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int>a;
		for(int i=0;i<n;i++)
		{
			int elem;
			cin>>elem;
			a.push_back(elem);
		}
		karray.push_back(a);
	}

	mergeksortedarray(karray);

}