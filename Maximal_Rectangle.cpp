class Solution {
public:
     int maxarea(vector<int>a)
    {
    int n=a.size();
	stack<int>s;
	int ans=0;
	for(int i=0;i<n;i++)
	{
		while(!s.empty())
		{
			if(a[s.top()]<=a[i])
			{
				break;
			}

			int j=s.top();
			s.pop();
			if(!s.empty())
			{
				ans=max(ans,a[j]*(i-s.top()-1));

			}
			else
				ans=max(ans,a[j]*i);
		}
		s.push(i);
	}

	while(!s.empty())
	{
		int j=s.top();
		s.pop();

		if(!s.empty())
		{
			ans=max(ans,a[j]*(n-s.top()-1));
		}
		else
			ans=max(ans,a[j]*n);
	}
	return ans;
    }
   
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        if(matrix.empty())
        {
            return 0;
        }
        
        vector<int>dp(matrix[0].size(),0);
        int max_area=0;
        int j=0;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]=='1')
                {
                    dp[j]=dp[j]+1; 
                }
                else
                {
                    dp[j]=0;
                } 
            }
           max_area=max(max_area,maxarea(dp));
             
        }
        return max_area;   
        
    }
    
    
    
};