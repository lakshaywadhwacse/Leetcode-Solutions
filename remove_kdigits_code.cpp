class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>s;
        s.push(num[0]);
        string ans="";
        for(int i=1;i<num.length();i++)
        {
            while(!s.empty() and k>0 and num[i]<s.top())
            {
                s.pop();
                k--;
            }
            s.push(num[i]);
            
        }
        
        while(!s.empty())
        {
            ans+=s.top();
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        int len= ans.size();
        
        if(k!=0)
        {
            ans.erase(len-k,k);
            
        }
        while(ans[0]=='0')
        {
            ans.erase(0,1);
        }
        return ans==""?"0":ans;
        
    }
};