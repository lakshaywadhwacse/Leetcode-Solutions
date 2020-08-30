#include<iostream>
#include<queue>
#include<unordered_map>
#include<list>
using namespace std;

bool canFinish(int numcourses, vector<vector<int>> &dependencies)
{
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
int main()
{
	int numCourses;
	cin>>numCourses;
	int edges; cin>>edges;
	vector<vector<int>>dependencies;

	for(int i=0;i<edges;i++)
	{
		int a,b;
		cin>>a>>b;
		dependencies.push_back({a,b});
	}

	if(canFinish(numCourses,dependencies)) cout<<"We can finish the courses";
	else cout<<"We can not finish the courses";

	return 0;
}