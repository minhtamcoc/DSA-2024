#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n+1];
        int dp[n+1];
        stack<int> st;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&a[i]>=st.top()){
                st.pop();
            }
            if(st.empty()) dp[i]=-1;
            else dp[i]=st.top();
            st.push(a[i]);
        }
        for(int i=0;i<n;i++) cout<<dp[i]<<" ";
        cout<<endl;
    }
    return 0;
}