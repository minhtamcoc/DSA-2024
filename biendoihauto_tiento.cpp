#include<bits/stdc++.h>
using namespace std;
bool check(char a){
    if(a=='+'||a=='-'||a=='*'||a=='/') return true;
    return false;
}
void solve(string s){
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
            string tmp=s[i]+y+x;
            st.push(tmp);
        }
    }
    cout<<st.top()<<endl;
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