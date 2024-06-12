#include<bits/stdc++.h>
using namespace std;
int n;
int in[1005];
int lev[1005];
struct node{
    int data;
    node*left,*right;
    node(int x){
        data=x;
        left=right=NULL;
    }
};
node*TREE(map<int,int> mp,vector<int> lv,int s,int e){
    if(s>e) return NULL;
    int rootdata=lv[0];
   node*root=new node(rootdata);
    int idx=mp[root->data];
    vector<int> l;
    vector<int> r;
    for(int i=1;i<lv.size();i++){
        if(mp[lv[i]]<idx) l.push_back(lv[i]);
        if(mp[lv[i]]>idx) r.push_back(lv[i]);
    }
    root->left=TREE(mp,l,s,idx-1);
    root->right=TREE(mp,r,idx+1,e);
    return root;
}
node*TREE_created(){
    map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[in[i]]=i;
    }
    vector<int> lv(lev,lev+n);
    return TREE(mp,lv,0,n-1);
}
void post_oder(node*root){
    if(root==NULL) return ;
    if(root->left) post_oder(root->left);
    if(root->right) post_oder(root->right);
    cout<<root->data<<" ";
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++) cin>>in[i];
        for(int i=0;i<n;i++) cin>>lev[i];
        node*root=NULL;
        root=TREE_created();
        post_oder(root);
        cout<<endl;
    }
    return 0;
}