#include<bits/stdc++.h>
using namespace std;
int check(char a){
    if(a=='+'||a=='-'||a=='*'||a=='/') return 1;
    return 0;
}
void solve(string s){
    stack<string> st;
    for(int i=s.size()-1;i>=0;i--){
        if(!check(s[i])){ // toan hang
            string tmp="";
            tmp+=s[i];
            st.push(tmp);
        }
        else{ // toan tu
            string x=st.top();
            st.pop();
            string y=st.top();
            st.pop();
            string tmp="("+x+s[i]+y+")";
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