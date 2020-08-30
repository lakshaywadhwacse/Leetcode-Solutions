#include<bits/stdc++.h>
using namespace std;
char a[1000];
vector<int>v;

class node{
public:
	int data;
	node* left;
	node* right;
	node(int d)
	{
		data=d;
		left=NULL;
		right=NULL;
	}
};

void StringtoInt()
{
	char* ans= strtok(a," ");
	while(ans!=NULL)
	{
		v.push_back(stoi(ans));
		ans=strtok(NULL," ");
	}
	// for(int i=0;i<v.size();i++)
	// {
	// 	cout<<v[i]<<" ";
	// }
}
node* createtree()
{
	if(strlen(a)==0 || v.size()==0) return NULL;
	int no=v[0];
	node*root= new node(no);
	queue<node*>q;
	q.push(root);
	int i=1;
	while(!q.empty() and i<v.size())
	{
		node* temp=q.front();
		q.pop();
		no= v[i++];
		temp->left=new node(no);
		q.push(temp->left);
		if(i>=v.size()) break;
		no=v[i++];
		temp->right=new node(no);
		q.push(temp->right);
		//if(i>=v.size()) break;
	}
	return root;
}

int sum(node* root)
{
	if(root==NULL) return 0;
	int leftsum=sum(root->left);
	int rightsum=sum(root->right);
	return root->data+leftsum+rightsum;
}

int countsubtree(node* root, int x)
{
	if(root==NULL) return 0;
	int ans=0;
	if(sum(root)==x)
	{
		ans=1;
	}

	int countleftsubtree=countsubtree(root->left,x);
	int countrightsubtree=countsubtree(root->right,x);

	return ans+countleftsubtree+countrightsubtree;

}



int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin.ignore();
		cin.getline(a,1000);
		StringtoInt();
		node* root= createtree();
		int x;
		cin>>x;
		cout<<countsubtree(root,x)<<endl;
	}

}