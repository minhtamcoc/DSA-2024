#include<bits/stdc++.h>
using namespace std;
int sex(char x){
    if(x=='+'||x=='-') return 1;
    if(x=='*'||x=='/') return 2;
    if(x=='^') return 3;
}
string check(string s){
    string res="";
    stack<char> st;
    for(int i=0;i<s.size();i++){
       if(isalpha(s[i])) res+=s[i];
       else if(s[i]=='(') st.push(s[i]);
       else if(s[i]==')'){
        while(!st.empty()&&st.top()!='('){
            res+=st.top();
            st.pop();
        }
        st.pop();
       }
       else{
        while(!st.empty()&&sex(st.top())>=sex(s[i])){
            res+=st.top();
            st.pop();
        }
        st.push(s[i]);
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