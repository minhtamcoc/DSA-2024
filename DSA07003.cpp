#include<bits/stdc++.h>
using namespace std;
string check(string s){
    stack<char> st;
    for(int i=0;i<s.size();i++){
        if(s[i]!=')'){
            st.push(s[i]);
        }
        else{
            int check=0;
            while(!st.empty()){
                char k=st.top();
                st.pop();
                if(k=='(') break;
               else if(k=='+'||k=='-'||k=='*'||k=='/') check=1;
            }
            if(check==0) return "Yes"; 
        }
    }
    if(st.empty()) return "No";
}
int main(){
    int t;
    cin>>t;
    cin.ignore();
    while(t--){
        string s;
        getline(cin,s);
        cout<<check(s)<<endl;
    }
    return 0;
}