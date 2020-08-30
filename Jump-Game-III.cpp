https://leetcode.com/problems/jump-game-iii/

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
    	vector<int>zeros;
    	for(int i=0;i<arr.size();i++)
    	{
    		if(arr[i]==0)zeros.push_back(i);

    	}

    	//2 To make a graph
    	map<int,list<int>>m;
    	for(int i=0;i<arr.size();i++)
    	{
    		if((i-arr[i])>=0)
    		{
    			m[i].push_back(i-arr[i]);
    		}
    		if((i+arr[i])<arr.size())
    		{
    			m[i].push_back(i+arr[i]);
    		}
    	}

    	// 3. Bfs traversal
    	map<int,bool>visited;
    	queue<int>q;
    	q.push(start);
    	visited[start]=true;
    	while(!q.empty())
    	{
    		int node=q.front();
    		q.pop();

    		for(auto child: m[node])
    		{
    			if(!visited[child])
    			{
    				q.push(child);
    				visited[child]=true;
    			}
    		}
    	}

    	// After traversal we will check the if there is any index which have zero as an element has been 
    	// visited or not

    	for(int i=0;i<zeros.size();i++)
    	{
    		if(visited[zeros[i]])
    		{
    			return true;
    		}
    	}
    	return false;
        
        
    }
};
