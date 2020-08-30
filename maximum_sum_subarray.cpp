//https://leetcode.com/problems/maximum-subarray/submissions/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int csum=0;
        int msum=INT_MIN;
        int maxelement=INT_MIN;
        
        for(int i=0;i<nums.size();i++)
        {
            csum+=nums[i];
             if(csum>msum)
            {
                msum=csum;
            }
            if(csum<0)
            {
                csum=0;
            }
        }
        return msum;
        
        
        
    }
};