class Solution{
public:
int ans=1;
int dfs_helper(map<int,list<int>>m,map<int,bool>&visited,int src)
{
	static int ans=0;
	visited[src]=true;
	for(auto child: m[src])
	{
		if(!visited[child])
		{
			ans++;
			dfs_helper(m,visited,child);
		}
	}
	return ans;
}

int dfs(map<int,list<int>>m)
{
	map<int,bool>visited;
	for(auto vertex: m)
	{
		int node=vertex.first;
		visited[node]=false;
	}
	int finalans=INT_MIN;
	for(auto vertex: m)
	{
		int node=vertex.first;
		if(!visited[node])
		{
			ans=1;
			finalans=max(finalans,dfs_helper(m,visited,node));
		}

	}
	return finalans;
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
	map<int,list<int>>m;
	for(int i=0;i<grid.size();i++)
	{
		for(int j=0;j<grid[0].size();j++)
		{
			int unique= i*grid[0].size()+j;
            
            if(grid[i][j]==1)
            {
                if((i-1>=0) and grid[i-1][j]==1)
                {
                    int temp= (i-1)*grid[0].size()+j;
                    m[unique].push_back(temp);
                    m[temp].push_back(unique);

                }

                if((j-1>=0) and grid[i][j-1]==1)
                {
                    int temp= (i)*grid[0].size()+(j-1);
                    m[unique].push_back(temp);
                    m[temp].push_back(unique);
                }
               // m[unique].push_back(unique);
                
            }

			
		}
	}
	return dfs(m);
}
    
    
    
};