class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<int,int>m;
        int sum=0;
        int mod=0;
        for(int i=0;i<nums.size();i++)
        {
            
            
            if(k!=0)
            {
                sum+=nums[i];
                mod=sum%k;
                m[0]=-1;
                 if(m.find(mod)==m.end())
                {
                    m[mod]=i;
                }
                else if(i-m[mod]>1)
                {
                    return true;
                } 
            }
            if(k==0 and i<nums.size()-1 and nums[i]==0 and nums[i+1]==0)
            {
                return true;
            }
            
            
        }
        return false;
        
        
    }
};