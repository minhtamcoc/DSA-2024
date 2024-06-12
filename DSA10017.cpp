#include<bits/stdc++.h>
using namespace std;
int V,E;
int a[1001][1001];
bool visited[1001];
int parent[1001]; // luu duong di
void BELLMAN_FORD(int s){
    int dp[1001];// luu ki luc
    for(int i=1;i<=V;i++){
        dp[i]=1e9;
        parent[i]=s;
    }
    dp[s]=0;
    visited[s]=true;
    for(int k=1;k<=V-1;k++){
            for(int i=1;i<=V;i++){
                    for(int j=1;j<=V;j++){
                            if(dp[j]>dp[i]+a[i][j]){
                                dp[j]=dp[i]+a[i][j];
                                parent[j]=i;
                            }
                    }
                }
            }
            for(int i=1;i<=V;i++) cout<<dp[i]<<" ";
    }
void solve(){
    cin>>V>>E;
    memset(a,1e9,sizeof(a));
    memset(visited,false,sizeof(visited));
    for(int i=1;i<=E;i++){
        int x,y,z;
        cin>>x>>y>>z;
        a[x][y]=z;
}
}