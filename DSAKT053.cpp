#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int main(){
    int t;
    cin>>t;
    cin.ignore();
    while(t--){
        string a,b;
        cin>>a>>b;
        int n=a.size();
        int m=b.size();
        memset(dp,0,sizeof(dp));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0||j==0) dp[i][j]=0;
                else{
                    if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1]+1;
                    else{
                        dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                    }
                }
            }
        }
        cout<<dp[n][m]<<endl;
    }
    return 0;
}