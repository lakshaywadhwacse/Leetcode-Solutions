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
	int index;
	TreeNode * CreateTree(vector<int>in, vector<int>post,int s, int e)
	{
		//Base case
		if(s>e)
		{
			return NULL;
		}
		int data= post[index];
		index--;
		TreeNode * root= new TreeNode(data);
		int k=-1;
		for(int i=s;i<=e;i++)
		{
			if(data==in[i])
			{
				k=i;
				break;
			}
		}

		root->right=CreateTree(in,post,k+1,e);
		root->left=CreateTree(in,post,s,k-1);

		return root;

	}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

    	index= inorder.size()-1;
    	return CreateTree(inorder,postorder,0,inorder.size()-1)


    }
};