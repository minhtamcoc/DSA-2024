#include<bits/stdc++.h>
using namespace std;
int n,k,s;
vector<vector<int>> v;
vector<int> c;
void Try(int i,int sum){
    if(sum>s) return;
    if(sum==s){
        v.push_back(c);
        return ;
    }
    for(int j=i;j<=n;j++){
        c.push_back(j);
        Try(j+1,sum+j);
        c.pop_back();
    }
}
int main(){
    while(1){
    cin>>n>>k>>s;
    if(n==0&&k==0&&s==0) break;
    Try(1,0);
    int res=0;
    for(int i=0;i<v.size();i++){
        if(v[i].size()==k) res++;
    }
    cout<<res<<endl;
    v.clear();
    }
    return 0;
}