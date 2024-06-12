#include<bits/stdc++.h>
using namespace std;
int V,E,M;
vector<int> v[1001];
int color[1001];
bool issafe(int u,int c){
    for(auto x:v[u]){
        if(color[x]==c) return false;
    }
    return true;
}
int solve(int c){
    int ans=0;
    for(int i=1;i<=V;i++){
        if(!color[i]&&issafe(i,c)){
            color[i]=c;
            ++ans;
        }
    }
    return ans;
}
void ins(){
    cin>>V>>E>>M;
    memset(v,0,sizeof(v));
    memset(color,0,sizeof(color));
    for(int i=1;i<=E;i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        ins();
        int res=0;
        int mau=1;
        while(res<V){
            res+=solve(mau++);
        }
        if(mau-1==M) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}