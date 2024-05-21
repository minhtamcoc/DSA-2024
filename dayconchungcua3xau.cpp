#include<bits/stdc++.h>
using namespace std;
int dp[101][101][101];
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,q;
        cin>>n>>m>>q;
        string a,b,c;
        cin>>a>>b>>c;
        memset(dp,0,sizeof(dp));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                for(int k=0;k<=q;k++){
                    if(i==0||k==0||j==0) dp[i][j][k]=0;
                    else if(a[i-1]==b[j-1]&&b[j-1]==c[k-1]) dp[i][j][k]=dp[i-1][j-1][k-1]+1;
                    else dp[i][j][k]=max(dp[i-1][j][k],max(dp[i][j-1][k],dp[i][j][k-1]));
                }
            }
        }
        cout<<dp[n][m][q]<<endl;
    }
    return 0;
}