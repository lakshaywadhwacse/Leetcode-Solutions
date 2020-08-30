#include<bits/stdc++.h>
using namespace std;
class help{
public:
	int r;
	int c;
	int depth;
	help(int r,int c, int depth)
	{
		this->r=r;
		this->c=c;
		this->depth=depth;
	}
};

int orangesRotting(vector<vector<int>>& grid) {
	int row_index[5]={0,0,-1,1};
	int col_index[5]={-1,1,0,0};
	queue<help> q;
	for(int i=0;i<grid.size();i++)
	{
		for(int j=0;j<grid[0].size();j++)
		{
			if(grid[i][j]==2)
			{
				q.push(help(i,j,0));
			}
		}
	}

	int ans=0;
	while(!q.empty())
	{
		help x= q.pop();
		int row=x.r;
		int col=x.col;
		int depth=x.depth;
		ans=max(ans,depth);
		for(int i=0;i<4;i++)
		{
			int new_row= row+ row_index[i];
			int col_index=col+col_index[i];

			if((new_row>=0 and new_row<r) and (new_col>=0 and new_col<c) and grid[new_row][new_col]==1)
			{
				grid[new_row][new_col]=2;
				q.push(help(new_row,new_col,depth+1));
			}

		}

		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				if(grid[i][j]==1) return -1;
			}
		}

		return ans;


	}


	

 }

int main()
{
	

}