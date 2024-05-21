#include<bits/stdc++.h>
using namespace std;
void solve(int n){
    queue<string> q;
    q.push("1");
    while(n--){
        string tmp=q.front();
        cout<<tmp<<" ";
        q.pop();
        q.push(tmp+"0");
        q.push(tmp+"1");
    }
    cout<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        solve(n);
    }
    return 0;
}