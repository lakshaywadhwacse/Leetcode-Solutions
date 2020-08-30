class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        map<int,int>m;
        list<int>*freq;
        int maxfreq=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            if(m.find(nums[i])!=m.end())
            {
                m[nums[i]]+=1;
            }
            else
            {
                m[nums[i]]=1;
            }
            maxfreq=max(maxfreq,m[nums[i]]);
        }
        
        
       freq= new list<int>[maxfreq+1];
       for(auto x: m)
       {
           freq[x.second].push_back(x.first);
       }
        
       for(int i=maxfreq;i>=0;i--)
       {
           if(k!=0)
           {
              for(auto x: freq[i])
              {
                  ans.push_back(x);
                  k--;
              }
              
           }
           
       }
       return ans;  
        
    }
};