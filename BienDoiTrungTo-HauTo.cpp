#include<bits/stdc++.h>
using namespace std;
int check(char a){
    if(a=='+'||a=='-') return 1;
    if(a=='*'||a=='/') return 2;
    if(a=='^') return 3;
    return -1;
}
string solve(string s){
    stack<char> st;
    string res="";
    for(int i=0;i<s.size();i++){
        if(s[i]=='(') st.push(s[i]);
        else if(isalnum(s[i])) res+=s[i];
        else if(s[i]==')'){
            while(!st.empty()){
                char k=st.top();
                st.pop();
                if(k=='(') break;
                res+=k;
            }
        }
        else {
            while(!st.empty()&&check(s[i])<=check(st.top())){
                char k=st.top();
                st.pop();
                res+=k;
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        char k=st.top();
        st.pop();
        if(k=='(') break;
        res+=k;
    }
    return res;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        cout<<solve(s)<<endl;
    }
    return 0;
}