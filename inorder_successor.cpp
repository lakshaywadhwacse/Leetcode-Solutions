
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool check=false;
TreeNode* Solution::getSuccessor(TreeNode* root, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(root==NULL) return NULL;
    TreeNode* left= getSuccessor(root->left,B);
    if(left) return left;
    
    if(check==true)
    {
        check=false;
        return root;
    }
    
    if(root->val==B)
    {
        check=true;
    }
    
    TreeNode* right= getSuccessor(root->right,B);
    if(right) return right;
    
    return NULL;
    
}
