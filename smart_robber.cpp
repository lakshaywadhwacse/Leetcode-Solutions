class Solution {
public:
    int rob(vector<int>& nums) {

        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums[1]);

        vector<int>loot(nums.size(),0);
        loot[0]=nums[0];
        loot[1]=max(nums[0],nums[1]);

        for(int i=2;i<nums.size();i++)
        {
            loot[i]=max(loot[i-2]+nums[i],loot[i-1]);
        }

        return loot[nums.size()-1];
    }
};