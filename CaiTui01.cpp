#include<bits/stdc++.h>
using namespace std;
int n,V;
// n la so do vat
// v la the tich cua tui
int w[1001];// trong luong
int value[1001];// gia tri
int dp[1001][1001];
int main(){
    int t;
    cin>>t;
    while(t--){
         cin>>n>>V;
         memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>value[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=V;j++){
                dp[i][j]=dp[i-1][j];// khong chon 
                if(j>=w[i]){
                    dp[i][j]=max(dp[i][j],dp[i-1][j-w[i]]+value[i]);
                }
        }
    }
    cout<<dp[n][V]<<endl;
    }
    return 0;
}