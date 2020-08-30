class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
    	map<int,int>m;
    	int ans=0;
    	m[0]=1;
    	int sum=0;
    	for(int i=0;i<nums.size();i++)
    	{
    		sum+=nums[i];
    		if(m.find(sum-k)!=m.end())
    		{
    			ans=ans+m[sum-k];
    		}
    		if(m.find(sum)!=m.end())
    		{
    			m[sum]+=1;
    		}
    		else
    		{
    			m[sum]=1;
    		}
    	}

    	return ans;
        
        
        
    }
};