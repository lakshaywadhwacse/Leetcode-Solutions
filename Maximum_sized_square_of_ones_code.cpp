#include<iostream>
using namespace std;

int maxSquareofOnesDP(vector<vector<char>> &matrix)
{
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
		dp[i][col-1] matrix[i][col-1]-'0';
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
			if(matrix[i][j]=='0') d[i][j]=0;
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



int max_side=0;
int maxSquareofOnes(vector<vector<char>> &matrix, int i, int j)
{

	//base case
	if(matrix.size()==0) return 0;

	if(i>=matrix.size()) return 0;

	if(j>=matrix[0].size()) return 0;


	// recursive case
	int step1= maxSquareofOnes(matrix,i,j+1);
	int step2= maxSquareofOnes(matrix,i+1,j);
	int step3= maxSquareofOnes(matrix,i+1,j+1);

	int ans=min(step1,min(step2,step3));

	if(matrix[i][j]=='0')
	{
		return 0;
	}
	else
	{
		ans++;
		max_side= max(max_side,ans);
		return ans;
	}

}



int main()
{
	int row,col;
	cin>>row>>col;

	vector<vector<char>> matrix;

	for(int i=0;i<rows;i++)
	{
		vector<char> temp(cols);
		for(int j=0;j<cols;j++)
		{
			cin>>temp[j];
		}
		matrix.push_back(temp);
	}

	// call to our recursive function

	int side= maxSquareofOnes(matrix,0,0);
	max_side= max(max_side, side);
	int area= max_side * max_side;
	cout<<area<<endll;

	//call to the function in which we will find our answer using Dynamic Programming
	cout<<maxSquareofOnes(matrix);
	return 0;
}