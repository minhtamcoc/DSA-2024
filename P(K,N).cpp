#include<bits/stdc++.h>
using namespace std;
const long long mode=1e9+7;
int n,k;
long long dp[1001][1001];
void solve(){
    dp[0][0]=1;
    for(int i=0;i<1001;i++){
        for(int j=0;j<1001;j++){
            if(j<=i){
               if(i==0&&j>0) dp[i][j]=0;
               else if(j==0) dp[i][j]=1;
               else dp[i][j]=(dp[i-1][j]%mode+j*dp[i-1][j-1]%mode)%mode;
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