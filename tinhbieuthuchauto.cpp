#include<bits/stdc++.h>
using namespace std;
bool check(char a){
    if(a=='+'||a=='-'||a=='*'||a=='/') return 1;
    return 0;
}
int res(int x,int y,char a){
    if(a=='+') return x+y;
    if(a=='-') return x-y;
    if(a=='*') return x*y;
    if(a=='/') return x/y;
}
void solve(string s){
    stack<int> st;
    for(int i=0;i<s.size();i++){ // no la so
        if(!check(s[i])){
            int tmp=s[i]-48;
            st.push(tmp);
        }
        else{ // toan hang
            int x=st.top();
            st.pop();
            int y=st.top();
            st.pop();
            int tmp=res(y,x,s[i]);
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