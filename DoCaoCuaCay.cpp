#include<bits/stdc++.h>
using namespace std;
int N;
vector<int> v[100005];
int parents[100005];
bool visited[100005];
void BFS(int u){
    queue<int> q;
    q.push(u);
    visited[u]=true;
    while(!q.empty()){
        int k=q.front();
        q.pop();
        for(auto x:v[k]){
            if(!visited[x]){
                q.push(x);
                visited[x]=true;
                parents[x]=k;
            }
        }
    }
}
void solve(){
    cin>>N;
    memset(v,0,sizeof(v));
    memset(visited,false,sizeof(visited));
    memset(parents,0,sizeof(parents));
    for(int i=1;i<=N-1;i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    BFS(1);
    int ans=-1e9;
    for(int i=1;i<=N;i++){
        int idx=i;
        int cnt=0;
        while(idx!=1){
            cnt++;
            idx=parents[idx];
        }
        ans=max(ans,cnt);
    }
    cout<<ans<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}