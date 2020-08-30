class Solution {
public:
    int trap(vector<int>& height) {
        int n= height.size();
        if(n==0) return 0;
        int *lmaxheight,*rmaxheight;
        lmaxheight= new int[n];
        rmaxheight=new int[n];
        lmaxheight[0]=0;
        for(int i=1;i<n;i++)
        {
            lmaxheight[i]=max(height[i-1],lmaxheight[i-1]);
        }
        
        rmaxheight[n-1]=0;
        for(int i=n-2;i>=0;i--)
        {
            rmaxheight[i]=max(height[i+1],rmaxheight[i+1]);
        }
        
        
        int store_water_val=0;
        for(int i=0;i<n;i++ )
        {
            int val=min(lmaxheight[i],rmaxheight[i]);
            if((val-height[i])>0)
            {
                store_water_val+=val-height[i];
            }
            
        }
        
        return store_water_val;
        
        
        
    }
};