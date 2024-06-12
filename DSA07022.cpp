#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n+1];
        map<int,int> mp;
        for(int i=0;i<n;i++){
            cin>>a[i];
            mp[a[i]]++;
        }
        int r[n+1];
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&mp[a[i]]>=mp[st.top()]){
                st.pop();
            }
            if(st.empty()) r[i]=-1;
            else r[i]=st.top();
            st.push(a[i]);
        }
        for(int i=0;i<n;i++) cout<<r[i]<<" ";
        cout<<endl;
    }
    return 0;
}