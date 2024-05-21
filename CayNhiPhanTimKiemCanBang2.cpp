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
void preoder(node*root){
    if(root==NULL) return ;
    cout<<root->data<<" ";
    if(root->left!=NULL) preoder(root->left);
    if(root->right!=NULL) preoder(root->right);
}
node*createBST(int a[],int s,int e){
    if(s>e) return NULL;
    int mid=(s+e)/2;
    node*root=new node(a[mid]);
    root->left=createBST(a,s,mid-1);
    root->right=createBST(a,mid+1,e);
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
        node*root=createBST(a,0,n-1);
        preoder(root);
        cout<<endl;
    }
    return 0;
}