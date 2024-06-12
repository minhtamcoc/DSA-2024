#include<bits/stdc++.h>
using namespace std;
int V,E;
vector<int> v[1001];
int in[1001];
void Set(){
    cin>>V>>E;
    memset(v,0,sizeof(v));
    memset(in,0,sizeof(in));
    for(int i=1;i<=E;i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        in[y]++;
    }
}
bool Kahn(){
    queue<int> q;
    for(int i=1;i<=V;i++){
        if(in[i]==0) q.push(i);
    }
    int cnt=0;
    while(!q.empty()){
        int k=q.front();
        q.pop();
        cnt++;
        for(auto x:v[k]){
            in[x]--;
            if(in[x]==0) q.push(x);
        }
    }
    if(cnt==V) return false;
    return true;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        Set();
        if(Kahn()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}