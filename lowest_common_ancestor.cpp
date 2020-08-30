/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* a, TreeNode* b) {
    if(root==NULL)return NULL;

	if(root==a || root==b)
	{
		return root;
	}

	TreeNode* left= lowestCommonAncestor(root->left,a,b);
	TreeNode *right= lowestCommonAncestor(root->right,a,b);

	if(!left and ! right) return NULL;

	else if(right and left) return root;

	return ((!left)? right: left);
}
        
};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	bool find(TreeNode* root, TreeNode* n)
	{
		if(root==NULL) return false;
		if(root->val==n->val) return true;
        bool left=find(root->left,n);
        bool right=find(root->right,n);
        return (left)? left: right;
		
	}


    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* a, TreeNode* b) {

    	if(root->val==a->val || root->val==b->val) return root;

    	if(find(root->left,a))
    	{
    		if(find(root->left,b)) return lowestCommonAncestor(root->left,a,b);
    		else return root;
    	}

    	else if(find(root->right,b)) return lowestCommonAncestor(root->right,a,b);

    	else return root;
}
        
};



    
    
