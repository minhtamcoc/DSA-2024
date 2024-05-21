#include<bits/stdc++.h>
using namespace std;
int V,E;
vector<int> v[1001];
bool visited[1001];
void dfs(int u){
    visited[u]=true;
    for(int x:v[u]){
        if(!visited[x]){
            dfs(x);
        }
    }
}
void ins(){
    cin>>V>>E;
    memset(v,0,sizeof(v));
    memset(visited,false,sizeof(visited));
    for(int i=1;i<=E;i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int res=0;// so thanh phan lien thong ban dau
    for(int i=1;i<=V;i++){
        if(!visited[i]){
            res++;
            dfs(i);
        }
    }
    for(int i=1;i<=V;i++){
        int ans=0;// so thanh phan lien thong sau khi bo dinh
         memset(visited,false,sizeof(visited));
         visited[i]=true;
        for(int j=1;j<=V;j++){
            if(!visited[j]){
                ans++;
                dfs(j);
        }
    }
    if(ans>res){
        cout<<i<<" ";
    }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        ins();
    }
}