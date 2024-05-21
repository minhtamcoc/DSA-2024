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
void bfs(int u){
    queue<int> q;
    q.push(u);
    while(!q.empty()){
        int k=q.front();
        q.pop();
        visited[k]=true;
        for(int x:v[k]){
            if(!visited[x]){
                  q.push(x); 
            }
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
    int cnt=0;
    for(int i=1;i<=V;i++){
        if(!visited[i]){
            cnt++;
            bfs(i);
        }
    }
    cout<<cnt<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        ins();
    }
    return 0;
}