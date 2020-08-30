class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int>m;
        int ans=0;
        int j=0;
        for(int i=0;i<s.size();i++)
        {
            char ch=s[i];
            if(m.find(ch)!=m.end())
            {
                j=max(j,m[ch]+1);
            }
            
            m[ch]=i;
            ans=max(ans,i-j+1);
        }
        
        return ans;  
    }
};