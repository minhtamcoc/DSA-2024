#include<bits/stdc++.h>
using namespace std;
struct node{
    int a,b,c,d,e,f;
};
bool check(node n,node m){
    if(n.a=m.a&&n.b==m.b&&n.c==m.c&&n.d==m.d&&n.e==m.e&&n.f==m.f) return true;
    return false;
}
void solve(){
    node n,m;
    cin>>n.a>>n.b>>n.c>>n.d>>n.e>>n.f;
    cin>>m.a>>m.b>>m.c>>m.d>>m.e>>m.f;
    queue<pair<node,int>> q;
    q.push({n,0});
    while(!q.empty()){
        pair<node,int> tmp=q.front();
        node k=tmp.first;
        int cnt=tmp.second;
        q.pop();
        if(check(k,m)){
            cout<<cnt<<endl;
            break;
        }
        // quay trai
        node res;
        res.a=k.d; res.b=k.a;
        res.c=k.c; res.d=k.e;
        res.e=k.b; res.f=k.f;  
        q.push({res,cnt+1});    
      // quay phai
        res.a=k.a; res.d=k.d;
        res.b=k.e; res.c=k.b;
        res.e=k.f; res.f=k.c;
        q.push({res,cnt+1});
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