#include<bits/stdc++.h>
using namespace std;
int N;
vector<int> v[1001];
bool visited[1001];
int res;
bool check;
void DFS(int s,int cnt,int t){
    if(check) return ;
    visited[s]=true;
    for(auto x:v[s]){
        if(!visited[x]){
            if(x==t){
                res=cnt;
                check=true;
            }
            DFS(x,cnt+1,t);
        }
    }
}
void solve(){
    cin>>N;
    memset(v,0,sizeof(v));
    for(int i=1;i<=N-1;i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int q;
    cin>>q;
    while(q--){
        int s,t;
        cin>>s>>t;
        res=0;
        check=false;
        memset(visited,false,sizeof(visited));
        DFS(s,1,t);
        cout<<res<<endl;
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