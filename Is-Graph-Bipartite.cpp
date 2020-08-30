https://leetcode.com/problems/is-graph-bipartite

class Solution {
public:
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
};
