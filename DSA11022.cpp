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
node*insert(node*root,int x){
    if(root==NULL) root=new node(x);
    if(x<root->data) root->left=insert(root->left,x);
    if(x>root->data) root->right=insert(root->right,x);
    return root; 
}
void solve(node*root){
    int cnt=0;
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node*tmp=q.front();
        q.pop();
        if(tmp->left!=NULL||tmp->right!=NULL) cnt++;
        if(tmp->left!=NULL){
            q.push(tmp->left);
        }
        if(tmp->right!=NULL) {
            q.push(tmp->right);
        }
    }
    cout<<cnt;
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
            root=insert(root,a[i]);
        }
        solve(root);
        cout<<endl;
    }
}