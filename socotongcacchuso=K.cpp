#include<bits/stdc++.h>
using namespace std;
const long long mode=1e9+7;
long long dp[101][50005];
int n,k;
void solve(){
 memset(dp,0,sizeof(dp));
        for(int i=0;i<=50005;i++) dp[0][i]=0;
        for(int i=0;i<=100;i++) dp[i][0]=0;
        for(int i=1;i<=9;i++) dp[1][i]=1;
        for(int i=2;i<=100;i++){
            for(int s=0;s<=9;s++){
            for(int j=1;j<=50000;j++){
                dp[i][j]=(dp[i][j]%mode+dp[i-1][j-s]%mode)%mode;
            }
        }
    }
}
int main(){
    int t;
    cin>>t;
    solve();
    while(t--){
        cin>>n>>k;
        cout<<dp[n][k]<<endl;
}
return 0;
}