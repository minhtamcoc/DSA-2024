#include<bits/stdc++.h>
using namespace std;
long long res=-1e9;
struct node{
	int data;
	node*left,*right;
	node(int x){
		data=x;
		left=right=NULL;
	}
};
void insert(node*root,int n1,int n2,char c){
	if(root==NULL) return ;
	if(root->data==n1){
		if(c=='L') root->left=new node(n2);
		else root->right=new node(n2);
	}
	else{
		insert(root->left,n1,n2,c);
		insert(root->right,n1,n2,c);
	}
}
long long LOAD(node*root){
	if(root==NULL) return 0;
	long long L=LOAD(root->left);
	long long R=LOAD(root->right);
	if(root->left==NULL&&root->right==NULL){
		return root->data;
	}
	if(root->left==NULL) return R+root->data;
	if(root->right==NULL) return L+root->data;
	if(root->left!=NULL&&root->right!=NULL){
		res=max(res,L+R+root->data);
		return max(L,R)+root->data;
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		node*root=NULL;
		while(n--){
			int n1,n2;
			char c;
			cin>>n1>>n2>>c;
			if(root==NULL){
				root=new node(n1);
				if(c=='L') root->left=new node(n2);
				else root->right=new node(n2);
			}
			else insert(root,n1,n2,c);
		}
		res=-1e9;
		LOAD(root);
		cout<<res<<endl;
	}
}