#include<bits/stdc++.h>
using namespace std;

bool isBipartite(vector<vector<int>>& graph) {
	int vertices=graph.size();
	vector<string> color(vertices,"white");

	// bfs code
	for(int i=0;i<vertices;i++)
	{
		  if(color[i]=="white")
		  {
			queue<int>q;
			q.push(i);
			color[i]="blue";
			while(!q.empty())
			{
				int parent=q.front();
				q.pop();
				int number_of_children=graph[parent].size();
				
				for(int j=0;j<number_of_children;j++)
				{
					int child=graph[parent][j];
					
					if(color[child]=="white")
					{
						if(color[parent]=="red") color[child]="blue";
						else color[child]="red";
						q.push(child);

					}
					else
					{
						if(color[parent]==color[child]) return false;
					}
				}
			}
		}
	}
    return true;
}

int main()
{
	int vertices; cin>>vertices;
	vector<vector<int>> graph;
	for(int i=0;i<vertices;i++)
	{
		int edges;
		cin>>edges;
		vector<int>temp(edges,0);
		for(int j=0;j<edges;j++)
		{
			cin>>temp[j];
		}

		graph.push_back(temp);
	}


	if(isBipartite(graph)) cout<<"Graph is Bipartite";
	else cout<<"Graph is not Bipartite";
	return 0;
}


//Input
// 10
// 2 1 9
// 3 8 7 2
// 3 1 6 3
// 3 2 5 4
// 3 3 6 9
// 2 6 3
// 4 2 5 7 4
// 3 1 9 6
// 2 1 9
// 3 0 7 4

