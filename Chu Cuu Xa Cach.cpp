#include<bits/stdc++.h>
using namespace std;
int n,k,m;
set<pair<pair<int,int>,pair<int,int>>> s;
vector<pair<int,int>> v;
bool check[105][105];
int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};
bool issafe(int x,int y){
    if(x>=1&&x<=n&&y>=1&&y<=n) return true;
    return false;
}
void DFS(int x,int y){
    check[x][y]=true;
    for(int k=0;k<4;k++){
        int x1=x+dx[k];
        int y1=y+dy[k];
        if(!check[x1][y1]&&issafe(x1,y1)&&s.count({{x,y},{x1,y1}})==0){
            DFS(x1,y1);
        }
    }
}
int main(){
   cin>>n>>k>>m;
    for(int i=1;i<=m;i++){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        s.insert({{x1,y1},{x2,y2}});
        s.insert({{x2,y2},{x1,y1}});
    }
    for(int i=1;i<=k;i++){
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    int cnt=0;
    for(auto x:v){
        memset(check,false,sizeof(check));
        DFS(x.first,x.second);
        for(auto y:v){
            if(!check[y.first][y.second]) cnt++;
        }
    }
    cout<<cnt/2<<endl;
    return 0;
}