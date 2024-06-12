#include<bits/stdc++.h>
using namespace std;
int k,n,m;
vector<int> v[1001];
bool visited[1001];
int x[1001];
void DFS(int u){
    visited[u]=true;
    for(auto h:v[u]){
        if(!visited[h]){
            DFS(h);
        }
    }
}

int main(){
    cin>>k>>n>>m;
    for(int i=1;i<=k;i++){
        cin>>x[i];
    }
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        memset(visited,false,sizeof(visited));
        int cnt=0;
        DFS(i);
        for(int j=1;j<=k;j++){
            if(visited[x[j]]) cnt++;
        }
       if(cnt==k) ans++;
    }
    cout<<ans<<endl;
    return 0;
}