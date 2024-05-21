#include<bits/stdc++.h>
using namespace std;
// su dung bang mau W G B
// 0 W
// 1 G
// 2 B
int V,E;
vector<int> v[1001];
int color[1001];
int check;
void DFS(int u){
    color[u]=1;
    for(auto x:v[u]){
        if(color[x]==0){
            color[x]=1;
            DFS(x);
        }
        else if(color[x]==1) check=1;
    }
    color[u]=2;
}
void solve(){
    cin>>V>>E;
    check=0;
    int res=0;
    memset(v,0,sizeof(v));
    memset(color,0,sizeof(color));
    for(int i=1;i<=E;i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
    }
        for(int i=1;i<=V;i++){
            if(color[i]==0){
                DFS(i);
            }
            if(check==1){
                cout<<"YES"<<endl;
                res=1;
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