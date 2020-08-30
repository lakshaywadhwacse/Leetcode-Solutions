
#include<bits/stdc++.h>
using namespace std;

int longestValidParenthesis(string s)
{
	stack<int>st;
	int ans=0,cur=0;
	int i=0;
	while(i<s.length())
	{
		if(s[i]=='(')
		{
			st.push(cur);
			cur=0;
		}
		else
		{
			if(st.empty())
			{
				cur=0;
			}
			else
			{
				cur=cur+st.pop()+2;
				st.pop();
				ans=max(cur,ans);
			}
		}
		i++;

	}
	return ans;
}