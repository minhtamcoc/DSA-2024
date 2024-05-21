#include<bits/stdc++.h>
using namespace std;
int check(string s){
    stack<int> st;
    st.push(-1);
    int res=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='(') st.push(i);
        else{
            st.pop();
            if(!st.empty()){
                int k=st.top();
                res=max(res,i-k);
            }
            else st.push(i);
        }
    }
    return res;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        cout<<check(s)<<endl;
    }
    return 0;
}