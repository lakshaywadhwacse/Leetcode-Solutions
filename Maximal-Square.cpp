https://leetcode.com/problems/maximal-square/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
    if(matrix.size()==0) return 0;
	int row= matrix.size();
	int col= matrix[0].size();
	int max_indp= 0;

	int **dp= new int*[row];

	for(int i=0;i<row;i++)
	{
		dp[i]= new int[col];
	}


	for(int j=0;j<col;j++)
	{
		dp[row-1][j]= matrix[row-1][j]-'0';
		max_indp= max(max_indp,dp[row-1][j]);
	}

	for(int i=0;i<row;i++)
	{
		dp[i][col-1] = matrix[i][col-1]-'0';
		max_indp=max(max_indp,dp[i][col-1]);
	}

	for(int i=row-2;i>=0;i--)
	{
		for(int j= col-2;j>=0;j--)
		{
			int step1= dp[i][j+1];
			int step2= dp[i+1][j];
			int step3= dp[i+1][j+1];

			int ans= min(step1,min(step2,step3));
			if(matrix[i][j]=='0') dp[i][j]=0;
			else
			{
				ans++;
				max_indp=max(max_indp,ans);
				dp[i][j]=ans;
			}
		}
	}

	return max_indp* max_indp;
        
    }
};
