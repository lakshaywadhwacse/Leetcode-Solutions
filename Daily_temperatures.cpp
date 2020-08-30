class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n=T.size();
        vector<int>ans(n,0);
        stack<int>s;
        int i=0;
        while(i<n)
        {
            while(!s.empty() and T[i]>T[s.top()])
            {
                ans[s.top()]=i-s.top();
                s.pop();
            }
            
            s.push(i);
            i++;
            
        }
        
        return ans;  
    }
};