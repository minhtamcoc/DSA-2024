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
void post_oder(node*root){
    if(root==NULL) return ;
    if(root->left!=NULL) post_oder(root->left);
    if(root->right!=NULL) post_oder(root->right);
    cout<<root->data<<" ";
}
node*insertROOT(node*root,int x){
    if(root==NULL) root=new node(x);
    if(x<root->data) root->left=insertROOT(root->left,x);
    if(x>root->data) root->right=insertROOT(root->right,x);
    return root;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int preoder[n+1];
        for(int i=0;i<n;i++) cin>>preoder[i];
        node*root=NULL;
        for(int i=0;i<n;i++){
            root=insertROOT(root,preoder[i]);
        }
        post_oder(root);
        cout<<endl;
    }
    return 0;
}