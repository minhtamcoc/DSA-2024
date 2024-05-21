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
void solve(node*root){
	queue<node*> q;
	q.push(root);
	int l=0;
	cout<<root->data<<" ";
	while(!q.empty()){
		vector<node*> v;
		int s=q.size();
		for(int i=0;i<s;i++){
			node*tmp=q.front();
			q.pop();
			if(tmp->left!=NULL) {
				q.push(tmp->left);
				v.push_back(tmp->left);
			}
			if(tmp->right!=NULL) {
				q.push(tmp->right);
				v.push_back(tmp->right);
		}
	}
	if(l%2==0){
		for(int i=0;i<v.size();i++) cout<<v[i]->data<<" ";
	}
	else{
		for(int i=v.size()-1;i>=0;i--) cout<<v[i]->data<<" ";
	}
	l++;
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
		solve(root);
		cout<<endl;
	}
	return 0;
}