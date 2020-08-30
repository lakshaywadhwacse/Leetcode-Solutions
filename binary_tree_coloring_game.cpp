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
    TreeNode* find(TreeNode* root, int x)
    {
        if(root==NULL) return NULL;
        if(root->val==x) return root;
        TreeNode* left=find(root->left,x);
        TreeNode* right=find(root->right,x);
        if(left==NULL)return right;
        else return left;
    }
    int count(TreeNode* root)
    {
        if(root==NULL)return 0;
        int leftcount=count(root->left);
        int rightcount=count(root->right);
        return 1+leftcount+rightcount;
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        TreeNode* t= find(root,x);
        if(t==root)
        {
             int left=count(t->left);
             int right=count(t->right);
             int remaining=n-(left+right);
            
            if(left>right+remaining) return 1;
            if(right>left+remaining) return 1;
            return 0;
            
        }
        else
        {
             int left=count(t->left);
             int right=count(t->right);
             int remaining=n-(left+right)-1;
             if(left>right+remaining) return 1;
             if(right>left+remaining) return 1;
             if(remaining> left+right+1) return 1;
            
            return 0;
            
        }
        
    }
};