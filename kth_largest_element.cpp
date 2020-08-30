class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {


        priority_queue<int,vector<int>,greater<int>>p;
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
        	if(count<k)
        	{
        		p.push(nums[i]);
        		count++;
        	}
        	else
        	{
        		if(nums[i]>p.top())
        		{
        			p.pop();
        			p.push(nums[i]);
        		}
        	}
        }

        return p.top();
        
        
    }
};