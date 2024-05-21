#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node*left,*right;
	node(int x){
		data=x;
		left=right=NULL;
	}
};
node*created(node*root,int x){
	if(root==NULL) root=new node(x);
	if(x<root->data) root->left=created(root->left,x);
	if(x>root->data) root->right=created(root->right,x);
	return root;
}
void pre_oder(node*root){
	if(root==NULL) return ;
	cout<<root->data<<" ";
	if(root->left) pre_oder(root->left);
	if(root->right) pre_oder(root->right);
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n+1];
		for(int i=0;i<n;i++) cin>>a[i];
		node*root=NULL;
		for(int i=0;i<n;i++){
			root=created(root,a[i]);
		}
		pre_oder(root);
		cout<<endl;
	}
		return 0;
}