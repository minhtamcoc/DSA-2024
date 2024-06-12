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
bool isPerfect(node*root,int level){
    queue<node*> q;
    q.push(root);
    int s=0,f=0,l=0;
    while(!q.empty()){
        s=q.size();
        f=0;
        if(s!=pow(s,l)) return false;
        for(int i=0;i<s;i++){
            node*t=q.front();
            q.pop();
            if(t->left!=NULL) q.push(t->left);
            if(t->right!=NULL) q.push(t->right);
        }
        l++;
    }
}
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
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        node root=NULL;
        while(n--){
            int n1,n2;
            cin>>n1>>n2;
            char c;
            cin>>c;
            if(r)
        }
    }
}