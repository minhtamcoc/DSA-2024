#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string a,b;
        cin>>a>>b;
        int n=a.size();
        int m=b.size();
        int dp[105][105];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0||j==0) dp[i][j]=i+j;
                else{
                    if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1];
                    else  dp[i][j]=min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]))+1;
                }
            }
        }
        cout<<dp[n][m]<<endl;
    }
    return 0;
}
