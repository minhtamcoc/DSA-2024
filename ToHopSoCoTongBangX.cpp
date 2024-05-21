#include<bits/stdc++.h>
using namespace std;
int n;
int a[10005];
struct node{
    int data;
    node*left,*right;
    node(int x){
        data=x;
        left=right=NULL;
    }
};
node*created(node*root,int i){
    if(i>=n) return NULL;
    if(root==NULL) root=new node(a[i]);
    root->left=created(root->left,2*i+1);
    root->right=created(root->right,2*i+2);
    return root;
}
void in_oder(node*root){
    if(root==NULL) return ;
    if(root->left!=NULL) in_oder(root->left);
    cout<<root->data<<" ";
    if(root->right!=NULL) in_oder(root->right);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        node*root=NULL;
        root=created(root,0);
        in_oder(root);
        cout<<endl;
    }
    return 0;
}