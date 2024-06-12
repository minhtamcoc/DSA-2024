#include<bits/stdc++.h>
using namespace std;
bool check(string s){
    for(int i=0;i<s.size()-1;i++){
        if(s[i]==s[i+1]) return false;
    }
    return true;
}
bool kt(string s){
    int res=0;
    for(int i=0;i<s.size();i++){
        int x=s[i]-'0';
        res+=x;
    }
    if(res%3==0) return true;
    return false;
}
string sort_string(string &s){
    for(int i=0;i<s.size();i++){
        int idx=i;
        for(int j=i+1;j<s.size();j++){
            if(s[idx]<s[j]){
                idx=j;
            }
        }
        swap(s[idx],s[i]);
    }
    return s;
}
void solve(int a[],int n){
    queue<string> q;
    set<string> st;
    for(int i=0;i<n;i++){
        string tmp=to_string(a[i]);
        if(a[i]%3==9) st.insert(tmp);
        q.push(tmp);
    }
    while(!q.empty()){
        string tmp=q.front();
        q.pop();
        if(tmp.size()==n) break; 
        for(int i=0;i<n;i++){
            string k=tmp;
            k=k+to_string(a[i]);
             k=sort_string(k);
            if(!check(k)) continue;
            if(kt(k)&&st.count(k)==0){
                q.push(k);
                st.insert(k);
            }
        }
    }
    if(st.size()==0) cout<<"-1"<<endl;
    else cout<<*st.rbegin()<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n+1];
        for(int i=0;i<n;i++) cin>>a[i];
        sort(a,a+n,greater<int>());
       solve(a,n);
    }
}