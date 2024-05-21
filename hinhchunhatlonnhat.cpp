#include<bits/stdc++.h>
using namespace std;
int main(){
        int m;
        cin>>m;
        int n;
        cin>>n;
        long long a[n];
        long long r[n];// ben phai dau tien nho hon no
        long long l[n];// ben trai dau tien nho hon no
        memset(r,0,sizeof(0));
        memset(l,0,sizeof(0));
        for(int i=0;i<n;i++) {
            int x;
            cin>>x;
            a[i]=m-x;
        }
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
        long long res=-1e9;
        for(int i=0;i<n;i++){
            res=max(res,(r[i]-l[i]+1)*a[i]);
        }
        cout<<res<<endl;
    return 0;
}

