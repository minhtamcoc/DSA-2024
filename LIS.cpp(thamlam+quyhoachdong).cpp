#include<bits/stdc++.h>
using namespace std;
int lis(int a[],int b[],int n){
    vector<pair<int,int>> p;
    pair<int,int> res=p[0];
    for(int i=1;i<=n;i++){
        if(res.first<a[i]&&res.second<b[i]){
            p.push_back({a[i],b[i]});
        }
        else{
            pair<int,int> x=make_pair(a[i],b[i]);
            auto it=lower_bound(p.begin(),p.end(),x);
            *it=x;
        }
    }
    return p.size();
}
int main(){
    int n;
    cin>>n;
    int a[n+1];
    int b[n+1];
    for(int i=0;i<n;i++) cin>>a[i]>>b[i];
    cout<<lis(a,b,n)<<endl;
    return 0;
}