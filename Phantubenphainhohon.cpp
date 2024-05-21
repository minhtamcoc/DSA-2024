#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n+1];
        int r[n+1]; // dau tien ben phai lon hon
        int l[n+1]; // dau tien ben trai nho hon
        for(int i=0;i<n;i++) cin>>a[i];
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&a[i]>=a[st.top()]){
                st.pop();
            }
            if(st.empty()) r[i]=-1;
            else r[i]=st.top();
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&a[i]<=a[st.top()]){
                st.pop();
            }
            if(st.empty())l[i]=-1;
            else l[i]=st.top();
            st.push(i);
        }
        for(int i=0;i<n;i++){
            if(r[i]==-1) cout<<"-1"<<" ";
            else {
                int x=l[r[i]];
                if(x==-1) cout<<"-1"<<" ";
                else cout<<a[x]<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}