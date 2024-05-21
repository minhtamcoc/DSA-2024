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
node*CreatedROOT(int a[],int s,int e){
    if(s>e) return NULL;
    int mid=(s+e)/2;
    node*root=new node(a[mid]);
    root->left= CreatedROOT(a,s,mid-1);
    root->right= CreatedROOT(a,mid+1,e);
    return root;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n+1];
        for(int i=0;i<n;i++) cin>>a[i];
        sort(a,a+n);
        node*root=CreatedROOT(a,0,n-1);
        post_oder(root);
        cout<<endl;
    }
    return 0;
}