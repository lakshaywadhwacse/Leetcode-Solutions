class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        if(n==0) return 0;
        stack<int>s;
        s.push(prices[0]);
        int i=1;
        int maxprofit=0;
        while(i<n)
        {
            if(prices[i]<s.top())
            {
                s.push(prices[i]);
            }
            else
            {
                int profit= prices[i]-s.top();
                maxprofit=max(profit,maxprofit);
            }
            i++;
            
        }
        return maxprofit;
    }
};