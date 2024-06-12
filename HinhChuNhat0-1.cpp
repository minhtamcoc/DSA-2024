#include<bits/stdc++.h>
using namespace std;
int N,M;
int a[505][505];
void solve(){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>a[i][j];
        }
    }
    int ans=-1e9;
    vector<int> x(M);
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(a[i][j]==0){
                x[j]=0;
            }
            else x[j]++;
        }
        stack<int> st;
        int l[M];
        int r[M];
        st.push(M);
        for(int k=M-1;k>=0;k--){
            while(st.size()>1&&x[k]<=x[st.top()]){
                st.pop();
            }
            r[k]=st.top()-1;
            st.push(k);
        }
        while(!st.empty()){
            st.pop();
        }
        st.push(-1);
        for(int k=0;k<M;k++){
            while(st.size()>1&&x[k]<=x[st.top()]){
                st.pop();
            }
            l[k]=st.top()+1;
            st.push(k);
        }
        for(int k=0;k<M;k++){
            ans=max(ans,(r[k]-l[k]+1)*x[k]);
        }
    }
    cout<<ans<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}