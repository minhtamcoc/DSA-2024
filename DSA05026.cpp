#include<bits/stdc++.h>
using namespace std;
int n,c;
int dp[105][25005];
int w[25005];
int main(){
    cin>>c>>n;
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=c;j++){
            dp[i][j]=dp[i-1][j];
            if(j>=w[i]){
                dp[i][j]=max(dp[i][j],dp[i][j-w[i]]+w[i]);
              }
        }
    }
    cout<<dp[n][c]<<endl;
    return 0;
}