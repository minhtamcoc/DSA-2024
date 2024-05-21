#include<bits/stdc++.h>
using namespace std;
int V,E;
vector<int> v[1001];
bool visited[1001];
vector<pair<int,int>> canh;
void dfs(int u){
    visited[u]=true;
    for(int x:v[u]){
        if(!visited[x]){
            dfs(x);
        }
    }
}
void dfs2(int u,int a,int b){
    visited[u]=true;
    for(int x:v[u]){
        if((x==a&&u==b)||(x==b&&u==a)) continue;
         if(!visited[x]){
            dfs2(x,a,b);
        }
    }
}
void ins(){
    cin>>V>>E;
    memset(v,0,sizeof(v));
    memset(visited,false,sizeof(visited));
   canh.clear();
    for(int i=1;i<=E;i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
        canh.push_back({x,y});
    }
    int res=0;
    for(int i=1;i<=V;i++){
        if(!visited[i]){
            res++;
            dfs(i);
        }
    }
    for(auto x:canh){
        int a=x.first;
        int b=x.second;
        int ans=0;
          memset(visited,false,sizeof(visited));
        for(int i=1;i<=V;i++){
            if(!visited[i]){
                ans++;
                dfs2(i,a,b);
            }
        }
        if(ans>res){
            if(a>b) cout<<b<<" "<<a<<" ";
            else cout<<a<<" "<<b<<" ";
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        ins();
        cout<<endl;
    }
}