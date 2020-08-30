class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

    	int element1=nums[0];
    	int elem1count=1;

    	int element2=0;
    	int elme2count=0;

    	for(int i=1;i<nums.size();i++)
    	{
    		if(a[i]==element1)
    		{
    			elem1count++;
    		}
    		else if(a[i]==element2)
    		{
    			elme2count++;
    		}
    		else if(elem1count==0)
    		{
    			element1=a[i];
    			elem1count=1;
    		}
    		else if(elme2count==0)
    		{
    			element2=a[i];
    			elme2count=1;
    		}
    		else
    		{
    			elem1count--;
    			elme2count--;
    		}
    	}

        int count1=0;
        int count2=0;
    	for(int i=0;i<nums.size();i++)
    	{
    		if(a[i]==element1) count1++;
    		else if(a[i]==element2) count2++;
    	}

    	vector<int>ans;
    	if(count1>num.size()/3) ans.push_back(element1);
    	if(count2>nums.size()/3) ans.push_back(element2);

    	return ans;

        
    }
};

//https://www.interviewbit.com/problems/majority-element/
// element greater than n/2;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int element=0;
        
        for(int i=0;i<nums.size();i++)
        {
            if(count==0)
            {
                element=nums[i];
            }
            if(nums[i]==element)count++;
            else count--;
        }
        
        int elemcount=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==element)elemcount++;
        }
        
        if(elemcount>(nums.size()/2)) return element;
        
    }  
         
};