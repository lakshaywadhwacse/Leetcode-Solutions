https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int n=prices.size();
	if(n==0||n==1)
	{
		return 0;
	}

	int *left= new int[n];
	int minl=prices[0];
	left[0]=0;
	for(int i=1;i<n;i++)
	{
		left[i]=max(left[i-1],prices[i]-minl);
		minl=min(minl,prices[i]);
	}

	int right=0,maxr=0;
	int ans=0;
	for(int i=n-1;i>=0;i--)
	{
		right=max(right,maxr-prices[i]);
		maxr=max(maxr,prices[i]);
		ans=max(ans,left[i]+right);
	}

	return ans;
        
    }
};
