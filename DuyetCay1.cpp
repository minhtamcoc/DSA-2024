#include<bits/stdc++.h>
using namespace std;
int n;
int in[1005];
int pre[1005];
struct node{
    int data;
    node*left,*right;
    node(int x){
        data=x;
        left=right=NULL;
    }
};
node*TREE(map<int,int> mp,int& preidx,int s,int e){
    if(s>e) return NULL;
    node*t=new node(pre[preidx++]);
    if(s==e) return t;
    int res=mp[t->data];
    t->left=TREE(mp,preidx,s,res-1);
    t->right=TREE(mp,preidx,res+1,e);
    return t;
}
node*Tree_created(){
    map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[in[i]]=i;
    }
    int preidx=0;
    return TREE(mp,preidx,0,n-1);
}
void post_oder(node*root){
    if(root==NULL) return ;
    if(root->left) post_oder(root->left);
    if(root->right) post_oder(root->right);
    cout<<root->data<<" ";
}
int main(){
   int t;
   cin>>t;
   while(t--){
        cin>>n;
        for(int i=0;i<n;i++) cin>>in[i];
        for(int i=0;i<n;i++) cin>>pre[i];
        node*root=Tree_created();
        post_oder(root);
        cout<<endl;
   }
   return 0;
}