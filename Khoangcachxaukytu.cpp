#include<bits/stdc++.h>
using namespace std;
int check(string a,string b){
    int cnt=0;
    for(int i=0;i<a.size();i++){
        if(a[i]!=b[i]) cnt++;
    }
    return cnt;
}
int solve(string s,string t,vector<string> a){
    if(s==t) return 0;
    queue<pair<string,int>> q;
    q.push({s,1});
    set<string> st;
    st.insert(s);
    while(!q.empty()){
        pair<string,int> tmp=q.front();
        string x=tmp.first;
        int cnt=tmp.second;
        q.pop();
        if(x==t){
            cout<<cnt<<endl;
            break;
        }
        for(int i=0;i<a.size();i++){
            if(check(x,a[i])==1&&st.count(a[i])==0){
                q.push({a[i],cnt+1});
                st.insert(a[i]);
            }
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s,t;
        string tmp;
        vector<string> a(n);
        cin>>s>>t;
        for(int i=0;i<n;i++) cin>>a[i];
        solve(s,t,a);
    }
    return 0;
}