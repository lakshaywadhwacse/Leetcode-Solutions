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
    void inorder(TreeNode* root, vector<int>&v)
    {
        if(root==NULL) return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
        
        return ;
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>v;
        inorder(root,v);
        return v[k-1];
        
        
    }
};


class Solution {
public:
    int smallest=INT_MAX;
    int inoder(TreeNode* root, int &k)
    {
        inoder(root->left,k);
        k--;
        if(k==0)
        {
            smallest=root->val;
        }
        inorder(root->right,k);
        return smallest;
    }
    int kthSmallest(TreeNode* root, int k) {
       return inorder(root,k);

        
        
        
    }
};