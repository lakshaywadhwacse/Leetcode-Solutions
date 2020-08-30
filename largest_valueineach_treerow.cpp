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
    vector<int> largestValues(TreeNode* root) {
        vector<int>ans;
        if(root==NULL) return ans;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        int max_val=INT_MIN;
        
        while(!q.empty())
        {
            TreeNode* node= q.front();
            q.pop();
            if(node==NULL)
            {
                ans.push_back(max_val);
                max_val=INT_MIN;
                if(!q.empty()) q.push(NULL);
            }
            else
            {
                max_val=max(max_val,node->val);
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
                
            }
        }
        return ans;
        
        
    }
};