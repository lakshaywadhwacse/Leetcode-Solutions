#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void wallsandGates(vector<vector<int>>& rooms)
{
	queue<pair<int,int>>q;
	vector<vector<int>>v;
	int r= rooms.size();

	if(r==0)
	{
		return;
	}

	int c = rooms[0].size();
	vector<vector<bool>>visited;
	for(int i=0;i<r;i++)
	{
		vector<bool>vis;
		for(int j=0;j<c;j++)
		{
			vis.push_back(false);
		}
		visited.push_back(vis);
	}

	for(int i=0;i<r;i++)
	{
		vector<int>v1;
		for(int j=0;j<c;j++)
		{
			if(rooms[i][j]==0)
			{
				q.push(make_pair(i,j));
				v1.push_back(0);
				visited[i][j]=true;
			}
			else
			{
				v1.push_back(-1);
			}

		}
		v.push_back(v1);
	}

	while(!q.empty())
	{
		pair<int,int>p;
		p=q.front();
		q.pop();
		if(p.first+1<r && !(visited[p.first+1][p.second]) && rooms[p.first+1][p.second]!=-1)
		{
			v[p.first+1][p.second]=v[p.first][p.second]+1;
			q.push(make_pair(p.first+1,p.second));
			visited[p.first+1][p.second]=true;

		}

		if(p.first-1>=0 && !(visited[p.first-1][p.second]) && rooms[p.first-11][p.second]!=-1)
		{
			v[p.first-1][p.second]=v[p.first][p.second]+1;
			q.push(make_pair(p.first-1,p.second));
			visited[p.first-1][p.second]=true;


		}

		if(p.second+1<c && !(visited[p.first][p.second+1]) && rooms[p.first][p.second+1]!=-1)
		{
			v[p.first][p.second+1]=v[p.first][p.second]+1;
			q.push(make_pair(p.first,p.second+1));
			visited[p.first][p.second+1]=true;

		}

		if(p.second-1>=0 && !(visited[p.first][p.second-1]) && rooms[p.first][p.second-1]!=-1)
		{
			v[p.first][p.second-1]=v[p.first][p.second]+1;
			q.push(make_pair(p.first,p.second-1));
			visited[p.first][p.second-1]=true;

		}
	}

	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			if(rooms[i][j]>0)
			{
				if(v[i][j]==-1)
				{
					v[i][j]=2147483647;
				}

				rooms[i][j]=v[i][j];
		    }
		}
	}

}

int main()
{
	vector<vector<int>>rooms{{INT_MAX,-1,0,INT_MAX},{INT_MAX,INT_MAX,INT_MAX,-1},{INT_MAX,-1,INT_MAX,-1},{0,-1,INT_MAX,INT_MAX}};
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			cout<<rooms[i][j]<<" ";
		}
		cout<<endl;
	}
	wallsandGates(rooms);
	// for(int i=0;i<4;i++)
	// {
	// 	for(int j=0;j<4;j++)
	// 	{
	// 		cout<<rooms[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }

}