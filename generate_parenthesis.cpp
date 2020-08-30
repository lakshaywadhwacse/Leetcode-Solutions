class Solution {
public:
    void generate(vector<string>&ans, string brackets, int open,int close,int n)
    {
        if(brackets.size()==2*n)
        {
            ans.push_back(brackets);
            return;
        }
        if(open<n)
        {
            generate(ans,brackets+"(",open+1,close,n);
        }
        if(close< open)
        {
            generate(ans,brackets+")",open,close+1,n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        generate(ans,"",0,0,n);
        return ans;
        
    }
};