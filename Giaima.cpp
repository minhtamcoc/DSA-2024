#include<bits/stdc++.h>
using namespace std;
int check(string s){
    if(s[0]=='0') return 0;   
    int dp[50];
    int n=s.size();
    memset(dp,0,sizeof(dp));
    s=" "+s;
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        if(s[i]>'0') dp[i]=dp[i-1];
        if(s[i-1]=='1'||s[i-1]=='2'&&s[i]<='6') dp[i]+=dp[i-2];
    }
    return dp[n];
}
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
    }
    return 0;
}
