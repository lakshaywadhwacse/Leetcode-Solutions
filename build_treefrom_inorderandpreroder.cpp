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
    int index=0;
    TreeNode* createtree(vector<int>pre,vector<int>in,int s,int e)
    {
        if(s>e)
        {
            return NULL;
        }
        
        int data=pre[index];
        TreeNode* root= new TreeNode(data);
        index++;
        int k=0;
        for(int i=s;i<=e;i++)
        {
            if(data==in[i])
            {
                k=i;
                break;
            }
        }
        
        root->left=createtree(pre,in,s,k-1);
        root->right=createtree(pre,in,k+1,e);
        return root;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return createtree(preorder,inorder,0,inorder.size()-1);
        
    }
};