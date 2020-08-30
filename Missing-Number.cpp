

class Solution {
public:
    int missingNumber(vector<int>& nums) {


        int ans1=0;
        int ans2=0;
        for(int i=0;i<=nums.size();i++)
        {
            ans1^=i;
        }

        for(int i=0;i<nums.size();i++)
        {
            ans2^=nums[i];
        }

        return ans1^ans2;
     
        
    }
};