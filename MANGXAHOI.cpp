#include<bits/stdc++.h>
using namespace std;
int V,E;
int parents[1001];
int num[1001];
int check;
void Set(){
    for(int i=1;i<=V;i++){
        parents[i]=i;
        num[i]=1;
    }
}
int Find(int u){
    if(u==parents[u]) return u;
    return Find(parents[u]);
}
void Union(int u,int v){
    int a=Find(u);
    int b=Find(v);
    if(a==b){
        return;
    }
    if(num[a]<num[b]) swap(a,b);
    parents[b]=a;
    num[a]+=num[b];
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>V>>E;
        Set();
        for(int i=1;i<=E;i++){
            int x,y;
            cin>>x>>y;
            Union(x,y);
        }
        int cnt=0;
        for(int i=1;i<=V;i++){
          if(Find(i)==i) cnt++;
        }
        if(cnt==1&&E==V+1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}