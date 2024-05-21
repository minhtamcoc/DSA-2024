#include<bits/stdc++.h>
using namespace std;
// cay la mot do thi vo huong ,lien thong ,khong co chu trinh
int V;
vector<int> v[1001];
bool visited[1001];
int parents[1001];
int check;
void DFS(int u){
    visited[u]=true;
    for(auto x:v[u]){
        if(!visited[x]){
            DFS(x);
        }
    }
}
void chutrinh(int u){
    visited[u]=true;
    for(auto x:v[u]){
        if(!visited[x]){
            parents[x]=u;
            chutrinh(x);
        }
        else if(x!=parents[u]) check=1;
    }
}
void solve(){
    cin>>V;
    check=0;
    memset(v,0,sizeof(v));
    memset(visited,false,sizeof(visited));
    for(int i=1;i<=V-1;i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    // kiem tra xem co lien thong khong
    int cnt=0;
    for(int i=1;i<=V;i++){
        if(!visited[i]){
            DFS(i);
            cnt++;
        }
    }
    // kiem tra co chu trinh hay khong
    int res=0;
        memset(visited,false,sizeof(visited));
        for(int i=1;i<=V;i++){
            if(!visited[i]){
                chutrinh(i);
            }
        }
        if(check==0&&cnt==1) cout<<"YES"<<endl;
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