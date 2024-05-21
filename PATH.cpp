#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> v[1001];
bool check[1001];
void bfs(int s){
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int k=q.front();
        q.pop();   
        check[k]=true;
        for(int x:v[k]){
            if(!check[x]){
                q.push(x);
            }
        }
    }
}
void ins(){
    cin>>n>>m;
    memset(v,0,sizeof(v));
    memset(check,false,sizeof(check));
    for(int i=1;i<=m;i++){
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
    memset(check,false,sizeof(check));
    bfs(s);
    if(!check[t]){
        cout<<"NO"<<endl;
    }
    else{
       cout<<"YES"<<endl;
    }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        ins();
    }
    return 0;
}