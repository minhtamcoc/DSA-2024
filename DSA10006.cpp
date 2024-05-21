#include<bits/stdc++.h>
using namespace std;
int V,E,u;
vector<int> v[1001];
bool visited[1001];
vector<pair<int,int>> T;
void DFS_TREE(int u){
    visited[u]=true;
    for(auto x:v[u]){
        if(!visited[x]){
            T.push_back({u,x});
            DFS_TREE(x);
        }
    }
}
void solve(){
    cin>>V>>E>>u;
    memset(v,0,sizeof(v));
    memset(visited,false,sizeof(visited));
    for(int i=1;i<=E;i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    DFS_TREE(u);
    if(T.size()==V-1){
        for(auto x:T){
            cout<<x.first<<" "<<x.second<<endl;
        }
    }
    else cout<<"-1"<<endl;
    T.clear();
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}