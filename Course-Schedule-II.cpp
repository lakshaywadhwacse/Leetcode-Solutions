https://leetcode.com/problems/course-schedule-ii

class Solution {
public:
    vector<int> findOrder(int numcourses, vector<vector<int>>& dependencies) {
    // the indegree vector
	vector<int>indegree(numcourses,0);
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
	for(int i=0;i<numcourses;i++)
	{
		if(indegree[i]==0)
		{
			zero_indegree.push(i);
		}

	}

	int edges_removed=0;// total edges removed in topological sort
	vector<int>order;
	while(!zero_indegree.empty())
	{
		int course=zero_indegree.front();
		zero_indegree.pop();
		order.push_back(course);
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
		return order;
	}
	else return {};
        
    }
};
