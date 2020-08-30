class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        
        int a0=rec1[0];
        int b0=rec1[1];
        int a1=rec1[2];
        int b1=rec1[3];
        
        int x0=rec2[0];
        int y0= rec2[1];
        int x1= rec2[2];
        int y1= rec2[3];
        
        if(x1<=a0 || y0>=b1 || x0>=a1 || y1<=b0)
        {
            return false;
        }
        else
        {
            return true;
        }
        
        
    }
};