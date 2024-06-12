#include<bits/stdc++.h>
using namespace std;
int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};
int a[505][505];
int R,C;
bool issafe(int x,int y){
    if(x>=0&&x<R&&y>=0&&y<C) return true;
    return false;
}
void solve(){
    cin>>R>>C;
    queue<pair<int,pair<int,int>>> q;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>a[i][j];
            if(a[i][j]==2) q.push({0,{i,j}});
        }
    }
    int ans=-1e9;
    while(!q.empty()){
        pair<int,pair<int,int>> tmp=q.front();
        q.pop();
        int cnt=tmp.first;
        ans=max(ans,cnt);
        int x=tmp.second.first;
        int y=tmp.second.second;
        for(int k=0;k<4;k++){
            int x1=x+dx[k];
            int y1=y+dy[k];
            if(issafe(x1,y1)&&a[x1][y1]==1){
                a[x1][y1]=2;
                q.push({cnt+1,{x1,y1}});
            }
        }
    }
    int cnt=0;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(a[i][j]==1) cnt++;
        }
    }
    if(cnt!=0) cout<<"-1"<<endl;
    else cout<<ans<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}