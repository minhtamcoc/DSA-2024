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
void change(node*root){
	queue<node*> q;
	q.push(root);
	vector<int> v;
	while(!q.empty()){
		node*tmp=q.front();
		q.pop();
		v.push_back(tmp->data);
		if(tmp->left) q.push(tmp->left);
		if(tmp->right) q.push(tmp->right);
	}
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
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
		change(root);
		cout<<endl;
	}
	return 0;
}