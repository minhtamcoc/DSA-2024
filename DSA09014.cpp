#include<bits/stdc++.h>
using namespace std;
int V,E;
vector<int> v[1001];
bool visited[1001];
int parents[1001];
// parents : bo
// u : con
int check;
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
            else if(x!=parents[k]) check=1;
        }
    }
}
void solve(){
    cin>>V>>E;
    check=0;
    int res=0;
    memset(v,0,sizeof(v));
    memset(visited,false,sizeof(visited));
    for(int i=1;i<=E;i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
  for(int i=1;i<=V;i++){ // de bai chua cho lien thong
        if(!visited[i]){
            BFS(i);
        }
        if(check==1){
            res=1;
            cout<<"YES"<<endl;
            break;
        }
}
    if(res==0) cout<<"NO"<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}