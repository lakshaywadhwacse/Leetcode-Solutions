#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>// max heap
#define pqs             priority_queue<int,vi,greater<int> >// min heap
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007// ans% mod
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
 
 
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
 
// int32_t main()
// {
//     //c_p_c();
//     //1. Vector of zeros

//     vector<int>zeros



    
    
//     return 0;
// }

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
    	vector<int>zeros;
    	for(int i=0;i<arr.size();i++)
    	{
    		if(arr[i]==0)zeros.push_back(i);

    	}

    	//2 To make a graph
    	map<int,list<int>>m;
    	for(int i=0;i<arr.size();i++)
    	{
    		if((i-arr[i])>=0)
    		{
    			m[i].push_back(i-arr[i]);
    		}
    		if((i+arr[i])<arr.size())
    		{
    			m[i].push_back(i+arr[i]);
    		}
    	}

    	// 3. Bfs traversal
    	bool visited[arr.size()]={0};
    	queue<int>q;

    	q.push(start);
    	visited[start]=true;
    	while(!q.empty())
    	{
    		int node=q.front();
    		q.pop();

    		for(auto child: m[node])
    		{
    			if(!visited[child])
    			{
    				q.push(child);
    				visited[child]=true;
    			}
    		}
    	}

    	// After traversal we will check the if there is any index which have zero as an element has been 
    	// visited or not

    	for(int i=0;i<zeros.size();i++)
    	{
    		if(visited[zeros[i]])
    		{
    			return true;
    		}
    	}
    	return false;







        
        
    }
};