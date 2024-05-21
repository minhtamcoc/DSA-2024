#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int insert,dele,copying;
        cin>>insert>>dele>>copying;
        int dp[105];// luu ket qua
        dp[1]=insert;
        for(int i=2;i<=n;i++){
            if(i%2==0) dp[i]=min(dp[i-1]+insert,dp[i/2]+copying);
            else dp[i]=min(dp[i-1]+insert,dp[(i+1)/2]+copying+dele);
        }
 cout<<dp[n]<<endl;
    }
    return 0;
}