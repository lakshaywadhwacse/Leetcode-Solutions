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

// // suppose we have to create a tree in then create tree function using preorder
// TreeNode* createtree()
// {
//     int data;
//     cin>>data;
//     if(data==-1) return NULL;
//     TreeNode*root= new TreeNode(data);
//     root->left=createtree();
//     root->right=createtree();

//     return root;
// }
class Solution {
public:
    void modifybst(TreeNode* root, int &sum)
    {
        if(root==NULL) return;
        modifybst(root->right,sum);
        sum+=root->val;
        root->val=sum;
        modifybst(root->left,sum);
        
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        int sum=0;
        modifybst(root,sum);
        return root;
        
    }
};