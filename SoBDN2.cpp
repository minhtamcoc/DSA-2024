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
    q.push("4");
    q.push("5"); 
    while(1){
        string tmp=q.front();
        q.pop();
        if(check(tmp)){
            cnt++;
            cout<<tmp<<" ";
        }
        q.push(tmp+"4");
        q.push(tmp+"5");
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