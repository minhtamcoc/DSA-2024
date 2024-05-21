#include<bits/stdc++.h>
using namespace std;
bool check(char a){
    if(a=='+'||a=='-'||a=='*'||a=='/') return true;
    return false;
}
string solve(string s){
    stack<string> st;
    for(int i=0;i<s.size();i++){
        if(!check(s[i])){
            string tmp="";
            tmp+=s[i];
            st.push(tmp);
        }
        else{
            string x=st.top();
            st.pop();
            string y=st.top();
            st.pop();
            string res=y+s[i]+x;
            st.push(res);
        }
    }
    return st.top();
}
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        cout<<solve(s)<<endl;
    }
}