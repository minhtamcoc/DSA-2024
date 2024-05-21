#include<bits/stdc++.h>
using namespace std;
int V,E;
vector<int> v[1001];
int color[1001];
bool bfs(int u){
    queue<int> q;
    q.push(u);
    color[u]=0;// RED
    while(!q.empty()){
        int k=q.front();
        q.pop();
        for(auto x:v[k]){
            if(color[x]==-1){
                color[x]=1-color[k];// blue;
                  q.push(x);
            }
            else if(color[x]==color[k]) return false;
        }
    }
    return true;
}
void solve(){
    cin>>V>>E;
    for(int i=1;i<=E;i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    bool ok=true;
    for(int i=1;i<=V;i++){
        if(color[i]==-1){
           if(!bfs(i)){
            ok=false;
            break;
           }
        }
    }
    if(ok) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}