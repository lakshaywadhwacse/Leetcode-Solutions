

vector<int> merge_util(vector<int>v1, vector<int>v2)
{
	int n1=v1.size();
	int n2=v2.size();
	int i=0;
	int j=0;
	vector<int>ans;
	while(i<n1 and j<n2)
	{
		if(v1[i]<=v2[j])
		{
			ans.push_back(v1[i]);
			i++;

		}
		else
		{
			ans.push_back(v2[j]);
			j++:
		}
	}
	while(i<n1)
	{
		ans.push_back(v1[i]);
		i++;

	}
	while(j<n2)
	{
		ans.push_back(v2[j]);
		j++;

	}
	return ans;


}
void build(vector<int>&v1, node* root)
{
	if(root==NULL) return;
	build(v1,root->left);
	v1.push_back(root->data);
	build(v1,root->right);

}
vector<int> merge(node* root1, node* root2)
{
	// Inorder of both bst to return two sorted array
	// Merge two sorted array in linear time
	vector<int>v1;
	vector<int>v2;
	build(v1,root1);
	build(v2,root2);
	return merge_util(v1,v2);

}

