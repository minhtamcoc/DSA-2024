#include<bits/stdc++.h>
using namespace std;
int n,m;
int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};
int a[505][505];
int dp[505][505];
bool visited[505][505];
void solve(){
    cin>>n>>m;
    memset(a,0,sizeof(a));
    memset(visited,false,sizeof(visited));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
             dp[i][j]=1e9;
        }
    }
        dp[0][0]=a[0][0];
     priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
     pq.push({dp[0][0],{0,0}}); // no se uu tien thang co dp nho nhat
     while(!pq.empty()){
        int x=pq.top().second.first;
        int y=pq.top().second.second;
        int res=pq.top().first;
        pq.pop();
        visited[x][y]=true;
        for(int k=0;k<4;k++){
            int i1=x+dx[k];
            int j1=y+dy[k];
            if(i1>=0&&i1<n&&j1>=0&&j1<m&&!visited[i1][j1]){
               if(dp[i1][j1]>res+a[i1][j1]){
                dp[i1][j1]=res+a[i1][j1];
                pq.push({dp[i1][j1],{i1,j1}});
               }
            }
        }
     }
    cout<<dp[n-1][m-1]<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}