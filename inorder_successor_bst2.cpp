class Solution
{
public:
	TreeNode* find(TreeNode* node)
	{
		if(node==NULL)
			return NULL;
		TreeNode* left= find(node->left);
		if(left)
		{
			return left;
		}

		return node;
	}
	TreeNode* inorderSuccessor(TreeNode* p)
	{

		Node* right= find(p->right);
		if(right!=NULL)
		{
			return right;
		}

		else
		{
			while(p->parent!=NULL and p.parent.right==p)
			{
				p=p.parent;
			}

			return p.parent;
		}

	}
}