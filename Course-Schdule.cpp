https://leetcode.com/problems/course-schedule/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& dependencies) {
    // the indegree vector
	vector<int>indegree(numCourses,0);
	// make a graph
	unordered_map<int,list<int>>graph;

	int total_edges=dependencies.size();
	for(int i=0;i<total_edges;i++)
	{
		graph[dependencies[i][1]].push_back(dependencies[i][0]);
		indegree[dependencies[i][0]]++;
	}

	// make queue for storing the node or courses having zero indegree
	queue<int>zero_indegree;
	for(int i=0;i<numCourses;i++)
	{
		if(indegree[i]==0)
		{
			zero_indegree.push(i);
		}

	}

	int edges_removed=0;// total edges removed in topological sort
	while(!zero_indegree.empty())
	{
		int course=zero_indegree.front();
		zero_indegree.pop();
		for(auto child: graph[course])
		{
			edges_removed++;
			indegree[child]--;
			if(indegree[child]==0)
			{
				zero_indegree.push(child);
			}
		}
	}

	if(edges_removed==total_edges)
	{
		return true;
	}
    else return false;
        
    }
};
