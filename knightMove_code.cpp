#include<bits/stdc++.h>
using namespace std;

class Graph{
private:
	map<pair<int,int>,list<pair<int,int>>>m1;
public:
	void addEdge(int i, int j, int m, int n)
	{
		pair<int,int>p=make_pair(i,j);
		if(i+2<m)
		{
			if(j-1>=0)
			{
				m1[p].push_back(make_pair(i+2,j-1));


			}
			if(j+1<n)
			{
				m1[p].push_back(make_pair(i+2,j+1));

			}

		}
		if(i-2>=0)
		{
			if(j-1>=0)
			{
				m1[p].push_back(make_pair(i-2,j-1));

			}

			if(j+1<n)
			{
				m1[p].push_back(make_pair(i-2,j+1));

			}

		}
		if(i+1<m)
		{
			if(j+2<n)
			{
				m1[p].push_back(make_pair(i+1,j+2));

			}

			if(j-2>=0)
			{
				m1[p].push_back(make_pair(i+1,j-2));

			}


		}
		if(i-1>=0)
		{
			if(j-2>=0)
			{
				m1[p].push_back(make_pair(i-1,j-2));

			}

			if(j+2<n)
			{
				m1[p].push_back(make_pair(i-1,j+2));
			}
		}
		return;
	}

	int BFS(int s1, int s2, int d1, int d2,int m, int n)
	{
		pair<int,int>src= make_pair(s1,s2);
		pair<int,int>dest=make_pair(d1,d2);

		map<pair<int,int>,bool>visited;
		map<pair<int,int>,int> distance;
		queue<pair<int,int>>q;

		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				visited[make_pair(i,j)]=false;
				distance[make_pair(i,j)]=INT_MAX;
			}
		}
		q.push(src);
		visited[src]=true;
		distance[src]=false;

		while(!q.empty())
		{
			pair<int,int>p=q.front();
			q.pop();

			for(auto child: m1[p])
			{
				if(!visited[child])
				{
					visited[child]=true;
					distance[child]=distance[p]+1;
					q.push(child);
				}
			}

		}

		int dist=distance[dest];
		if(dist==INT_MAX)
		{
			dist=-1;

		}
		return dist;

	}


};

int main()
{
	int t,n,m,s1,s2,d1,d2;
	cin>>t;
	while(t--)
	{
		cin>>m>>n;
		Graph g;
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				g.addEdge(i,j,m,n);
			}
		}
		cin>>s1>>s2>>d1>>d2;
		s1--;s2--;
		d1--,d2--;

		cout<<g.BFS(s1,s2,d1,d2,m,n)<<endl;
	}
}