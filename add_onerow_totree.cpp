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
    TreeNode* add(TreeNode* root, int depth, int v, int d)
    {
        if(root==NULL) return NULL;
        
        if(depth==d-1)
        {
            TreeNode* newleft, *newright;
            newleft=new TreeNode(v);
            newright= new TreeNode(v);
            
            newleft->left= root->left;
            newright->right=root->right;
            root->left=newleft;
            root->right=newright;
            
        }
        else
        {
            add(root->left,depth+1,v,d);
            add(root->right,depth+1,v,d);
        }
        
        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d==1)
        {
            TreeNode* newroot= new TreeNode(v);
            newroot->left=root;
            return newroot;
        }
        return add(root,1,v,d);
    }
};