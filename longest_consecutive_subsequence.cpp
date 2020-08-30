class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>arr;
        set<int>done;
        for(int i:nums) arr.insert(i);
        int max=0;
        for(int i:arr)
        {
            if(done.find(i)!=done.end()) continue;
            int c=0;
            int j=i;
            while(arr.find(j)!=arr.end())
            {
                c++;
                done.insert(j++);  
            }
            j=i-1;
            while(arr.find(j)!=arr.end())
            {
                c++;
                done.insert(j--);
            }
            if(max<c) max=c;
        }
        return max;
        
    }
};