#include<bits/stdc++.h>
using namespace std;
int V,E,s;
vector<int> v[1001];
bool visited[1001];
int X[1001];
vector<vector<int>> T;
void hamilton(int k){ // dinh thu k;
    for(auto x:v[X[k-1]]){
        if(k==V+1&&x==s){
                vector<int> c;
                for(int i=1;i<=V;i++){
                    c.push_back(X[i]);
                }
                c.push_back(s);
                T.push_back(c);
        }
        else if(!visited[x]){
            visited[x]=true;
            X[k]=x;
            hamilton(k+1);
            visited[x]=false;
        }
    }
}
void hamilton_cycle(int s){
    X[1]=s;
    visited[s]=true;
    hamilton(2);
}
void solve(){
    cin>>V>>E>>s;
    memset(visited,false,sizeof(visited));
    memset(X,0,sizeof(X));
    memset(v,0,sizeof(v));
    for(int i=1;i<=E;i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
    }
    hamilton_cycle(s);
    for(int i=0;i<T.size();i++){
        for(int j=0;j<T[i].size();j++){
            cout<<T[i][j]<<" ";
        }
        cout<<endl;
    }
    T.clear();
}
int main(){
    solve();
    return 0;
}
