#include<bits/stdc++.h>
using namespace std;
class node{
public:
	int data;
	node*left,*right;
	node(int d)
	{
		data=d;
		left=right=NULL;
	}
};

void inorder(node* root)
{
	if(root==NULL) return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

node* specialtree(int *a, int start, int end,int size)
{
	if(start>end) return NULL;
	int k=start;
	for(int i=start;i<=end;i++)
	{
		if(a[i]>a[k])
		{
			k=i;
		}
	}

	node* root= new node(a[k]);
	root->left= specialtree(a,start,k-1,size);
	root->right=specialtree(a,k+1,end,size);

	return root;

}
int main(){
	int n;
	cin>>n;
	int *a= new int[n];
	for(int i=0;i<n;i++)cin>>a[i];

	node* root=specialtree(a,0,n-1,n);
    inorder(root);
   

}