#include<bits/stdc++.h>
using namespace std;
void solve(int n){
    queue<string> q;
    q.push("1");
    while(1){
        string tmp=q.front();
        q.pop();
    
        if(res%n==0){
            cout<<res<<endl;
            break;
        }
        q.push(tmp+"0");
        q.push(tmp+"1");
    }
}
int mmain(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        solve(n);
    }
    return 0;
}