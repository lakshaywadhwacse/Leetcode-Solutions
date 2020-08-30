class Solution {
public:
    string sortfun(string s)
    {
        sort(s.begin(),s.end());
        return s;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,list<string>>m;
        for(int i=0;i<strs.size();i++)
        {
            string s= sortfun(strs[i]);
            m[s].push_back(strs[i]);
        }
    
        vector<vector<string>>ans;
        for(auto v:m)
        {
            string s= v.first;
            vector<string>vsmall;
            for(auto elem:m[s])
            {
                
                vsmall.push_back(elem);
            }
            ans.push_back(vsmall);
        }
        
        return ans;
    }
};