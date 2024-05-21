#include<bits/stdc++.h>
using namespace std;
int V,E,s;
vector<pair<int,int>> v[1001];
bool visited[1001];
void DIJKSTRA(int s){
    int n=V;
    int dp[V+1];
    dp[s]=0;
    for(int i=1;i<=V;i++){
        if(i!=s) dp[i]=1e9;
    }
    while(n>0){
        int res=1e9;
        int u=-1;
        for(int i=1;i<=V;i++){
            if(!visited[i]&&res>dp[i]){
                res=dp[i];
                u=i;
            }
        }
        if(u==-1) break;
        visited[u]=true;
        for(auto x:v[u]){
            if(!visited[x.first]){
                dp[x.first]= min(dp[x.first],res+x.second);
            }
        }
        n--;
    }
    for(int i=1;i<=V;i++) cout<<dp[i]<<" ";
}
void solve(){
    cin>>V>>E>>s;
    memset(v,0,sizeof(v));
    memset(visited,false,sizeof(visited));
    for(int i=1;i<=E;i++){
        int x,y,z;
        cin>>x>>y>>z;
        v[x].push_back({y,z});
        v[y].push_back({x,z}); // trong truong hop mang hai chieu
    }
        DIJKSTRA(s);
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
