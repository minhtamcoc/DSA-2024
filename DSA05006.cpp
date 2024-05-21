#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[1005];
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
            long long dp[1005]={0};
            long long res=0;
         for(int i=1;i<=n;i++){
            dp[i]=a[i];
            for(int j=1;j<=i;j++){
                if(a[i]>a[j]&&dp[i]<dp[j]+a[i]){
                    dp[i]=dp[j]+a[i];
                }
            }
                res=max(res,dp[i]);
            }
         cout<<res<<endl;
    }
    return 0;
}