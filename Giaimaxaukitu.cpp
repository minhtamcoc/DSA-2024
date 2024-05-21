#include<bits/stdc++.h>
using namespace std;
void solve(string s){
    stack<char> st;
    for(int i=0;i<s.size();i++){
        if(s[i]!=']') st.push(s[i]);
        else {
            string res="";
            while(st.top()!='['){
                res=st.top()+res;
                st.pop();
            }
           if(!st.empty()) st.pop();// xoa dau ngoac
            string tmp="";
            while(!st.empty()&&st.top()>='0'&&st.top()<='9'){
                tmp=st.top()+tmp;
                st.pop();
            }
            int cnt=stoi(tmp);
            string idx="";
            for(int i=1;i<=cnt;i++){
                idx+=res;
            }
            for(auto x:idx) st.push(x);
        }
    }
    string ans="";
    while(!st.empty()){
        ans=st.top()+ans;
        st.pop();
    }
        cout<<ans<<endl;
    }
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
       solve(s);
    }
    return 0;
}