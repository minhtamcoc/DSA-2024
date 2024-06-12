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
bool check(node*root){
    if(root==NULL) return true;
    if(root->left==NULL&&root->right==NULL) return true;
    int sum_left=0;
    if(root->left) sum_left=root->left->data;
    int sum_right=0;
    if(root->right) sum_right=root->right->data;
    if(root->data==sum_left+sum_right){
        return check(root->left)&&check(root->right);
    }
    else return false;
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
            else insert(root,n1,n2,c);
        }
        if(check(root)) cout<<"1"<<endl;
        else cout<<"0"<<endl;
    }
    return 0;
}