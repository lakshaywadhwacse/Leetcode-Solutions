/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

    	queue<TreeNode*>q;
    	vector<vector<int>>ans;
    	vector<int>a;
    	if(root==NULL) return ans;
    	int l=0;

    	q.push(root);
    	q.push(NULL);

    	while(!q.empty())
    	{
    		TreeNode* x= q.front();
    		q.pop();

    		if(x==NULL)
    		{
    			if(l%2==0)
    			{
    				ans.push_back(a);
    			}
    			else
    			{
    				reverse(a.begin(),a.end());
    				ans.push_back(a);
    			}
    			l++;

    			if(!q.empty())
    			{
    				q.push(NULL);
    			}

    			while(!a.empty())
    			{
    				a.pop_back();
    			}
    		}

    		else
    		{
    			a.push_back(x->val);
    			if(x->left)
    			{
    				q.push(x->left);
    			}
    			if(x->right)
    			{
    				q.push(x->right);
    			}

    		}
    	}


    	return ans;  
    }
};