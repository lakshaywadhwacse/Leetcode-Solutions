https://leetcode.com/problems/friend-circles/

class Solution {
public:
    
void dfs_helper(map<int,vector<int>>m,map<int,bool>&visited,int src)
{

	visited[src]=true;
	for(auto child: m[src])
	{
		if(!visited[child])
		{
			dfs_helper(m,visited,child);
		}
	}

	return ;

}



int dfs(map<int,vector<int>>m,int n)
{
	map<int,bool>visited;
	for(int i=0;i<n;i++)
	{
		visited[i]=false;
	}
	dfs_helper(m,visited,0);
	int components=1;
	for(int i=1;i<n;i++)
	{
		if(!visited[i])
		{
			dfs_helper(m,visited,i);
			components++;
		}
	}

	return components;
}

int findCircleNum(vector<vector<int>>&M)
{
	map<int,vector<int>>m;
	int n=M.size();
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(M[i][j])
			{
				m[i].push_back(j);
			}
		}
	}

	return dfs(m,n);

}
};
