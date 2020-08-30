
#include<iostream>
using namespace std;

int ways(int i, int j)
{
	if(i==0 && j==0) return 0;
	else if(i==0 || j==0) return 1;
	return ways(i,j-1)+ways(i-1,j);
}


int top_down(int i, int j, int **dp)
{
	if(dp[i][j]==-1)
	{
		if(i==0 && j==0)
		{
			dp[i][j]=0;
			return 0;
		}
		else if(i==0|| j==0)
		{
			dp[i][j]=1;
			return 1;
		}
		dp[i][j]=top_down(i,j-1,dp)+top_down(i-1,j,dp);
		return dp[i][j];
	}

	else return dp[i][j];
}
 int uniquePaths(int m, int n) {
        
        int arr[100][100]={0};
        int row=n;
        int col=m;
        int i=0;
        for(int j=0;j<col;j++)
        {
            arr[i][j]=1;
             
        }
        int j=0;
        for(int i=0;i<row;i++)
        {
            arr[i][j]=1; 
        }
        
        for(int i=1;i<row;i++)
        {
            for(int j=1;j<col;j++)
            {
                arr[i][j]=arr[i-1][j]+arr[i][j-1];
            }
        }
        
        return arr[row-1][col-1]; 
    }

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		cout<<ways(n-1,m-1);

		int **dp= new int*[n];

		for(int i=0;i<n;i++)
		{
			dp[i]= new int[m];
			for(int j=0;j<m;j++)
			{
				dp[i][j]=-1;
			}
		}

		cout<<top_down(n-1,m-1,dp);

		cout<<bottom_up(n,m);
	}
}