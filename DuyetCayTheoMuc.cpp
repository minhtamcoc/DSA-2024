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
void levelOrder(node*root){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node*nd=q.front();
        q.pop();
        cout<<nd->data<<" ";
        if(nd->left!=NULL) q.push(nd->left);
        if(nd->right!=NULL) q.push(nd->right);
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
                else root->right= new node(n2);
            }
            else{
                insert(root,n1,n2,c);
            }
        }
        levelOrder(root);
        cout<<endl;
    }
    return 0;
}