#include<bits/stdc++.h>
using namespace std;
int V,E,s,t;
vector<int> v[1001];
bool visited[1001];
void ins(){
    cin>>V>>E>>s>>t;
    memset(v,0,sizeof(v));
    memset(visited,false,sizeof(visited));
    for(int i=1;i<=E;i++){
        int x;
        int y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
}
void dfs(int x){
    
}