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
node*created(node*root,int x){
    if(root==NULL) root=new node(x);
    if(x<root->data) root->left=created(root->left,x);
    if(x>root->data) root->right=created(root->right,x);
    return root;
}
void right_level_oder(node*root){
    queue<node*> q;
    q.push(root);
    int l=0;
    while(!q.empty()){
        int s=q.size();
        for(int i=0;i<s;i++){
            node*tmp=q.front();
            q.pop();
            cout<<tmp->data<<" ";
            if(tmp->right) q.push(tmp->right);
            if(tmp->left) q.push(tmp->left);
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
        int a[n+1];
        for(int i=0;i<n;i++) cin>>a[i];
        node*root=NULL;
        for(int i=0;i<n;i++){
            root=created(root,a[i]);
        }
        right_level_oder(root);
        cout<<endl;
    }
    return 0;
}