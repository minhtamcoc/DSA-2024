#include<bits/stdc++.h>
using namespace std;
// chia du
// dua ve bai toan day con dai nhat co tong bang s
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        int a;
        cin>>n>>k;
        int dp[101][101];
        dp[0][0]=0;
        for(int i=1;i<k;i++) dp[0][i]=-1e9;
        for(int i=1;i<=n;i++){
            cin>>a;
            a%=k;
            for(int j=0;j<k;j++){
                dp[i][j]=max(dp[i-1][j],dp[i-1][(j+k-a)%k]+1);
            }
        }
        cout<<dp[n][0]<<endl;
    }
    return 0;
}