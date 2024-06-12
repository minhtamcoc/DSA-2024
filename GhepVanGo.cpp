#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n+1];
        for(int i=0;i<n;i++) cin>>a[i];
        int l[n+1];
        int r[n+1];
        stack<int> st;
        st.push(n);
        for(int i=n-1;i>=0;i--){
            while(st.size()>1&&a[i]<=a[st.top()]){
                st.pop();
            }
            r[i]=st.top()-1;
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        st.push(-1);
        for(int i=0;i<n;i++){
            while(st.size()>1&&a[i]<=a[st.top()]){
                st.pop();
            }
                l[i]=st.top()+1;
                st.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int x=r[i]-l[i]+1;
            if(x>=a[i]) ans=max(ans,a[i]);
        }
        cout<<ans<<endl;
    }
}