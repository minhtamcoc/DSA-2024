#include<bits/stdc++.h>
using namespace std;
void solve(long long n){
    queue<string> q;
    q.push("1");
    int cnt=0;
    while(1){
        string tmp=q.front();
        long long res=stoll(tmp);
        if(res<=n) cnt++;
        else break;
          q.pop();
        q.push(tmp+"0");
        q.push(tmp+"1");
    }
    cout<<cnt<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        solve(n);
    }
    return 0;
}