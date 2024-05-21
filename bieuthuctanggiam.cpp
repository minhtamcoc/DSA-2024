#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        s=" "+s;
        stack<int> st;
        for(int i=1;i<=s.size();i++){
            if(s[i]=='D') st.push(i);
            else{
                cout<<i;
                while(!st.empty()){
                    cout<<st.top();
                    st.pop();
                }
            }
        }
        cout<<endl;
    }
    return 0;
}