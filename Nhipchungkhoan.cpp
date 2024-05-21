#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n+1];
        int b[n+1];
        for(int i=0;i<n;i++) cin>>a[i];
        stack<int> st;
        st.push(-1);
        for(int i=0;i<n;i++){
            while(st.size()>1&&a[i]>=a[st.top()]){
                st.pop();
            }
            b[i]=st.top();
            st.push(i);
        }
        for(int i=0;i<n;i++) cout<<i-b[i]<<" ";
        cout<<endl;
    }
    return 0;
}