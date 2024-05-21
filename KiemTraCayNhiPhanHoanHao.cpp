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
string isperfect(node*root){
    queue<node*> q;
    q.push(root);
    int l=0;
    while(!q.empty()){
        int s=q.size();
        if(s!=pow(2,l)) return "No";
        for(int i=1;i<=s;i++){
            node*k=q.front();
            q.pop();
            if(k->left!=NULL) q.push(k->left);
            if(k->right!=NULL) q.push(k->right);
        }
        l++;
    }
    return "Yes";
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
                else root->right=new node(n2);
            }
            else{
                insert(root,n1,n2,c);
            }
        }
        cout<<isperfect(root)<<endl;
    }
    return 0;
}