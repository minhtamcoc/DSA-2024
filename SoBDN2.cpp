#include<bits/stdc++.h>
using namespace std;
int check(string s){
    int i=0;
    int j=s.size()-1;
    while(i<j){
        if(s[i]!=s[j]) return 0;
        i++;
        j--;
    }
    return 1;
}
void solve(int n){
    queue<string> q;
    q.push("44");
    q.push("55");
    q.push("54");
    q.push("45");
    int cnt=0;
    while(1){
        string tmp=q.front();
        q.pop();
        if(cnt==n) break;
        if(check(tmp)){
            cnt++;
            cout<<tmp<<" ";
        }
        q.push(tmp+"44");
        q.push(tmp+"55");
        q.push(tmp+"54");
        q.push(tmp+"45");
    
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        solve(n);
        cout<<endl;
    }
    return 0;
}