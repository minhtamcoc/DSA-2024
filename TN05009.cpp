#include<bits/stdc++.h>
using namespace std;
int V,E;
vector<int> v[1001];
bool visited[1001];
int check;
int t;
int a[1001];
void dfs(int u,int parents){
    visited[u]=true;
    for(auto x:v[u]){
        if(!visited[x]){
            a[x]=u;
            dfs(x,u);
        }
        else if(x!=parents){
            check=1;
            t=u;
        }
    }
}
void solve(){
    cin>>V>>E;
    check=0;
    memset(v,0,sizeof(v));
    memset(visited,false,sizeof(visited));
    
    for(int i=1;i<=E;i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1,0);
    if(check==0) cout<<"NO"<<endl;
      else{
        cout<<t<<endl;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}