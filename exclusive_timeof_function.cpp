class Solution {
public:
    void convert(string &logs, int &id, int &time, string &operation)
    {
        id=0,time=0;
        int j=0;
        while(logs[j]!=':')
        {
            id=id*10+ logs[j]-'0';
            j++;
            
        }j++;
        operation="";
        while(logs[j]!=':')
        {
            operation+=logs[j];
            j++;   
        }j++;
        
        while(j<logs.size())
        {
            time=time*10+logs[j]-'0';
            j++;
        }
        
        if(operation=="end") time++;
        
    }
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int>duration(n,0);
        stack<int>s;
        for(int i=0;i<logs.size();i++)
        {
            
            int id,time; string operation;
            int prev_optime;
            convert(logs[i],id,time,operation);
            if(!s.empty())
            {
                int fn_id=s.top();
                duration[fn_id]+=(time-prev_optime);
            }
            prev_optime=time;
            
            if(operation=="start")
            {
                s.push(id);
            }
            else
            {
                s.pop();
            }   
            
        }
        return duration;
        
    }
};