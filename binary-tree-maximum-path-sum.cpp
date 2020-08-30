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
    
    int maxsum=INT_MIN;
    int treemaxsum(TreeNode* root)
    {
         if(root==NULL)
        {
            return INT_MIN;
        }
        
        int leftsum= treemaxsum(root->left);
        int rightsum= treemaxsum(root->right);
        
        int ans=root->val;
        if(leftsum>0) ans+=leftsum;
        if(rightsum>0)ans+=rightsum;
        maxsum=max(maxsum,ans);
        return root->val+max(0,max(leftsum,rightsum));
    }
    int maxPathSum(TreeNode* root) {
        treemaxsum(root);
        return maxsum;    
    }
};