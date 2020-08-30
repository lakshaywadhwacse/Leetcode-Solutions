https://leetcode.com/problems/unique-paths/

class Solution {
public:
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
};
