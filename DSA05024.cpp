#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        long long dp[n+5]={0};
        dp[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=min(i,k);j++){
                if(i>=j){
                    dp[i]+=dp[i-j]%mod;
                    dp[i]%=mod;
                }
            }
        }
        cout<<dp[n]<<endl;
        }
    }