class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        
        for(auto x:m)
        {
            if(m[x.first]>=2) return true;
        }
        return false;
        
        
        
    }
};


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,bool>m;

        for(int i=0;i<num.size();i++)
        {
            if(m.find(nums[i])!=m.end()) return true;
            else m[nums[i]]=true;
        }
        return false;   
    }
};


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,bool>m;

        for(int i=0;i<nums.size();i++)
        {
            if(m.count(nums[i])==1) return true;
            else m[nums[i]]=true;
        }
        return false;   
    }
};