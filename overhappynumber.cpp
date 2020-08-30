//https://leetcode.com/problems/happy-number/submissions/
class Solution {
public:
    int update(int n)
    {
        int s=0;
        while(n>0)
        {
            int d=n%10;
            s= s+ d*d;
            n=n/10;
        }
        return s;
    }
    bool check(map<int,bool>m, int n)
    {
        if(n==1) return true;
        
        if(m.find(n)!=m.end()) return false;
        m.insert(make_pair(n,true));
        n=update(n);
        
        return check(m,n);
    }
    
    bool isHappy(int n) 
    {
        map<int,bool>m;
        return check(m,n);
        
    }
};