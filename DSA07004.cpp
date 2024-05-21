#include<bits/stdc++.h>
using namespace std;
int check(string s){
    stack<char> st;
    int dem=0;
    for(int i=0;i<s.size();i++){
           if(s[i]=='(') st.push(s[i]);
           else{
            if(st.empty()){
                dem++;
             st.push('(');
            }
            else {
                st.pop();
            }
           }
    }
    return dem+st.size()/2;
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