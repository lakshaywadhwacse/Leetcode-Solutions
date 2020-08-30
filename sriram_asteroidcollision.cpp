class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>s;
        for(int i=0;i<asteroids.size();i++)
        {
            //collison condition
            if(!s.empty() and s.top()>0 and asteroids[i]<0)
            {
                bool flag=false;
                while(!s.empty() and s.top()>0 and asteroids[i]<0)
                {
                    if(abs(asteroids[i])==abs(s.top()))
                    {
                        s.pop();
                        flag=false;
                        break;
                    }
                    else if(abs(asteroids[i])>abs(s.top()))
                    {
                        s.pop();
                        flag=true;
                    }
                    else if(abs(asteroids[i])<abs(s.top()))
                    {
                        flag=false;
                        break;
                    }
                }
                if(flag) s.push(asteroids[i]);
                
            }
            else
            {
                // Not collide just need to insert the element in stack
                s.push(asteroids[i]);
            }
        }
        
        vector<int>ans;
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};