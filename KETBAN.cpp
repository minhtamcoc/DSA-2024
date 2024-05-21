#include<bits/stdc++.h>
using namespace std;
int V,E;
vector<int> v[100001];
bool visited[100001];
vector<int> T;
void BFS(int u){
    queue<int> q;
    q.push(u);
    visited[u]=true;
    while(!q.empty()){
        int k=q.front();
        T.push_back(k);
        q.pop();
        for(auto x:v[k]){
            if(!visited[x]){
                visited[x]=true;
                q.push(x);
            }
        }
    }
}
void solve(){
    cin>>V>>E;
    memset(v,0,sizeof(v));
    memset(visited,false,sizeof(visited));
    for(int i=1;i<=E;i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int ans=-1e9;
    for(int i=1;i<=V;i++){
        if(!visited[i]){
            BFS(i);
        }
        int x=T.size();
        ans=max(ans,x);
        T.clear();
    }
    cout<<ans<<endl;
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