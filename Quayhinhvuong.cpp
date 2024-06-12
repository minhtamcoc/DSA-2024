#include<bits/stdc++.h>
using namespace std;
struct node{
    int a,b,c,d,e,f;
};
bool check(node x,node y){
    if(x.a==y.a&&x.b==y.b&&x.c==y.c&&x.d==y.d&&x.e==y.e&&x.f==y.f) return true;
    return false;
}
void solve(){
    node x,y;
    cin>>x.a>>x.b>>x.c>>x.d>>x.e>>x.f;
    cin>>y.a>>y.b>>y.c>>y.d>>y.e>>y.f;
    queue<pair<node,int>> q;
    q.push({x,1});
    while(!q.empty()){
        pair<node,int> tmp=q.front();
        q.pop();
        node k=tmp.first;
        int cnt=tmp.second;
        // phai
        node k1;
        k1.a=k.a; k1.d=k.d;
        k1.b=k.e; k1.e=k.f;
        k1.c=k.b; k1.f=k.c;
        q.push({k1,cnt+1});
        // trai
        node k2;
        k2.a=k.b; k2.d=k.a;
        k2.b=k.e; k2.e=k.d;
        k2.c=k.c; k2.f=k.f;
        q.push({k2,cnt+1});
        if(check(k,k1))

    }
}
int main(){
    int t;
    cin>>t;
    while(){
        solve();
    }
    return 0;
}