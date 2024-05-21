#include<bits/stdc++.h>
using namespace std;
void solve(int n){
    queue<pair<int,int>> q;
    q.push({n,0});
    set<int> s;
    s.insert(n);
    while(!q.empty()){
        pair<int,int> tmp=q.front();
        int x=tmp.first;
        int cnt=tmp.second;
        q.pop();
        if(x==1){
            cout<<cnt<<endl;
            break;
        }
        if(x-1>0&&s.count(x-1)==0){
            q.push({x-1,cnt+1});
            s.insert(x-1);
        }
        for(int i=2;i<=sqrt(x);i++){
            if(x%i==0){
                int res=max(i,x/i);
                if(res>0&&s.count(res)==0){
                    q.push({res,cnt+1});
                    s.insert(res);
                }
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
        solve(n);
    }
    return 0;
}