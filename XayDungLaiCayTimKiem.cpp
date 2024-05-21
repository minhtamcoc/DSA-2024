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
node*insertROOT(node*root,int x){
    if(root==NULL) root=new node(x);
    if(x<root->data) root->left=insertROOT(root->left,x);
    if(x>root->data) root->right=insertROOT(root->right,x);
    return root;
}
void preoder(node*root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    if(root->left!=NULL) preoder(root->left);
    if(root->right!=NULL) preoder(root->right);
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
            root=insertROOT(root,a[i]);
        }
        preoder(root);
        cout<<endl;
    }
    return 0;
}