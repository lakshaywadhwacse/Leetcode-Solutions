class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,list<int>>m;
        for(int i=0;i<nums.size();i++)
        {
            if(m.find(nums[i])!=m.end())
            {
                for(auto val:m[nums[i]])
                {
                    if(abs(i-val)<=k) return true;
                }
                
            }
            m[nums[i]].push_back(i);
        }
        
        return false;
        
    }
};