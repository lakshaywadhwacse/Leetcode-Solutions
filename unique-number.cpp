//https://leetcode.com/problems/single-number/submissions/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans1=0;
        for(int i=0;i<nums.size();i++)
        {
            ans1^=nums[i];
        }
        return ans1;
        
    }
};